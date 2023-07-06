import numpy as np
import env
import copy 
from scipy.optimize import minimize

class congestion_game(env.all_player) :
     def __init__(self, coefficient, path_num, player_num) : 
          #upper bound parameters
          self.gamma = 1
          self.V = 0
          self.lamb = 0.0

          #path related matters
          self.path_cost = np.zeros(path_num) 
          self.cost_func = list()
          for i in coefficient :
               self.cost_func.append(np.poly1d(i))

          #players' related matters
          env.all_player.__init__(self, player_num=player_num, path_num=path_num)
          self.players_choice = dict()              #record all player's final choice (just for that round)
          self.all_play_total_path_select = []      #DICT [{1:[path1's cost]}] specific cost for each round
          self.all_player_cost = []                 #record all players' cost for all rounds (T*player_num matix) 
          self.strategy_record = []                 #record player's strategy for all rounds (T*path_num matrix)

          #measurement tool-- regret
          self.regret_sum = 0
          self.regret_sum_record = []               #和 hightsight_real_diff紀錄一樣
          self.average_regret = []
          self.hindsight_real_diff = 0

          #measurement tool-- potential
          self.average_potential = []
          
          #measurement tool-- path variance
          self.path_cost_record = []                    #record all path cost for all round (T*road_number matrix)
          self.cost_variance_record = []                #to record each path's cost variance
     

     def get_cost_func (self) :
          return self.cost_func
     
     #each palyer choose one path according their distribution
     def select_cost(self) : 
          self.players_choice = {new_list: [] for new_list in range(self.path_num)} 
          #creat empty dict => {0:[], 1:[], 2:[]}
          for i in range (self.player_num) :
               choice_path = np.random.choice(
                   a=self.path_num,
                   size=1,
                   p=self.players_strategy[i].estimate_probability) 
               self.players_choice[choice_path[0]].append(i)
          path_sum={}# [0:5,1:5]
           
          for path ,driver in self.players_choice.items() :
               path_sum[path]=(len(driver))
               path_cost = self.cost_func[path](len(driver)) #calculate path cost
               self.path_cost[path] = path_cost   
          self.path_cost_record.append(copy.deepcopy(self.path_cost))
          self.strategy_record.append(copy.deepcopy(self.players_strategy[0].probability))
          # print("path cost : ", self.path_cost)
          self.all_play_total_path_select.append(path_sum)
          return self.path_cost
     
     #以下3個function 處理最佳化問題
     def object(strategy, last_strategy, cost, learn_rate) :
          return cost.dot(strategy.T) + (1/learn_rate)*(strategy - last_strategy).dot((strategy - last_strategy).T)
 
     def constraint(strategy) :
          return np.sum(strategy)- 1
     
     def refresh_strategy_minimize(last_strategy, cost, learn_rate) :
          x0 = np.full((1, len(last_strategy)), 1/len(last_strategy))
          b = (0, 1)
          buds = []
          for i in range(len(last_strategy)) :
               buds.append(b)
          cons = [{'type' : 'eq', 'fun' : congestion_game.constraint}]
          sol = minimize(fun=congestion_game.object, 
                         x0=x0, 
                         args=(np.array(last_strategy),
                               np.array(cost), 
                               learn_rate), 
                         method='SLSQP', 
                         bounds=buds,
                         constraints=cons)
          return sol.x

     #strategy update
     def update_strategy(self, times, learn_rate, scale) :

          if learn_rate == 'paper' :
               learn_rate = (self.gamma/(self.lamb+self.path_num*self.gamma))**0.5

          for i in range(self.player_num) : 
               self.players_strategy[i].probability =  congestion_game. refresh_strategy_minimize(
                   self.players_strategy[i].probability,
                   self.path_cost, 
                   learn_rate)
               # self.players_strategy[i].probability = [0.615, 0.163, 0.207, 0.015]
          return copy.deepcopy(self.players_strategy[0].probability)

     def update_estimate_strategy(self, times, learn_rate, scale) :

          if learn_rate == 'paper' :
               try:
                   learn_rate = (self.gamma/(self.lamb+self.path_num*self.gamma))**0.5
               except :
                   learn_rate = (1/(self.lamb+self.path_num*1))**0.5
          for i in range(self.player_num) :
               self.players_strategy[i].estimate_probability =  congestion_game.refresh_strategy_minimize(
                   self.players_strategy[i].probability,
                   self.path_cost, 
                   learn_rate)      
          # print("player estimate strategy : ",  self.players_strategy[0].estimate_probability) 
     
     def get_key(self,val, players_choice):
        for key, value in players_choice.items():
            if val in value:
                return key

     #regret measurement
     def hindsight(self) :                    #offline algorithm can change their arm in every step
          self.hindsight_real_diff = 0
          cost_record = []
          for number in range(self.player_num) :
               real_path = self.get_key(number, self.players_choice)           #本回合實際的路徑
               real_cost = self.path_cost[real_path]                           #本回合實際的cost
               cost_record.append(real_cost)                                   #tmep list for all path cost matrix

               hindsight_cost = float('inf')                            #後見之明最低cost
               exclude_path_select = copy.deepcopy(self.players_choice)
               exclude_path_select[real_path].remove(number)
               for path ,driver in exclude_path_select.items() :
                    path_cost = self.cost_func[path](len(driver)+1) #calculate path cost
                    if path_cost < hindsight_cost :
                         hindsight_cost = path_cost        
               self.hindsight_real_diff = self.hindsight_real_diff + (real_cost - hindsight_cost) 
               #所有人的[真實選擇與後見之明的差異]的總和
          self.all_player_cost.append(cost_record)


     def best_road_cost(self) :
          all_path_cost = np.array(self.path_cost_record)
          best_cost = float('inf')
          for path in range(self.path_num) :
               if np.sum(all_path_cost[:, path]) < best_cost :
                    best_cost = np.sum(all_path_cost[:, path])
                    best_road = all_path_cost[:, path]
          return best_road
 
     def hindsight_weak_version(self, T) :      #offline algorithm can't change choice
          diff_set = []
          best_road = self.best_road_cost()
          for times in range(T) :
               diff_fixed_road = 0
               for player in range(self.player_num) :
                    diff_fixed_road += self.all_player_cost[times][player] - best_road[times]
               diff_set.append(diff_fixed_road)
          return diff_set

     def fixed_acu_regret_func(self, fixed_regret) :
         fixed_acu_regret = []
         for i in range(1, len(fixed_regret)+1) :
             fixed_acu_regret.append(sum(fixed_regret[0:i]))  
         return fixed_acu_regret
               
     
     #variance measurement
     def variance_function(self) :
         cost_history = self.path_cost_record.T
         to_variance = []
         for i in range(len(self.path_num)) :
             to_variance.append(np.var(cost_history[i]))
         self.cost_variance_record.append(to_variance)
 
     #potential measurement
     def potential_function(self) : #cost_func is a set of poly1d
        potential_value=0
        for path, driver in self.players_choice.items() :
            for i in range(0, len(driver)+1) :
                potential_value = potential_value + self.cost_func[path](i)   
        return potential_value 
                         
     #update upper bound parameters
     def expected_loss(self, num) :           #calculate expected loss for each path. [cost func(expected flow)]
         mu_ = []                             #num means which strategy you want to select(here, we use -1(current) or -2(previous))
         for path in range(self.path_num) :
             exp_player = self.player_num*self.strategy_record[num][path]
             mu_.append(self.cost_func[path](exp_player))
         return np.array(mu_)
               
     def lambda_update(self) :
         mu = self.expected_loss(-1)
         temp = (self.path_cost - mu)**2
         self.lamb += float(self.players_strategy[0].probability.dot(temp))
         

     def V_update(self) :
         try:
             mu_previous = self.expected_loss(-2)
         except :
             mu_previous = self.expected_loss(-1)
         mu_current = self.expected_loss(-1)

         self.V += max(abs(mu_current-mu_previous)) 
 
     def play_a_game(self,T, gradient_times, learn_rate, scale): 
        #control update frequency times
        update_frequency = 1  
        #real measurement data
        regret, acu_regret, p_value, upper_bound  = [], [], [], []
       
        for i in range(1, int(T/update_frequency)+1) :
            #algorithm
            self.update_estimate_strategy(gradient_times, learn_rate, scale)
            for times in range(update_frequency) :    #in this period, player's strategy would not change
                self.select_cost()
                #regret measurement
                self.hindsight()
                regret.append(copy.deepcopy(self.hindsight_real_diff))
                acu_regret.append(sum(regret))
                #self.regret_sum_record.append(copy.deepcopy(self.regret_sum))
                self.average_regret.append(sum(regret)/i)#30rounds 1~30
                #potential measurement
                p_value.append(self.potential_function())
                self.average_potential.append(sum(p_value)/i)#30rounds 1~30
                #regret upper bound  (for each person, not total muti agents)  
                self.lambda_update()
               #  self.gamma += 1        #upper bound parameter gamma changes once players strategy update
                if times % update_frequency == 0 :
                    self.V_update()    #upper bound parameter V changes once players strategy update
                upper_bound.append(copy.deepcopy((((self.gamma*self.lamb)**0.5)+(self.path_num**0.5)*self.gamma)*self.player_num))
            #algorithm
            self.path_cost = sum(self.path_cost_record[-update_frequency:])/(update_frequency)
            self.update_strategy(gradient_times, learn_rate, scale)#if self.strategy_record is not bug,this can del
            


        fixed_regret = self.hindsight_weak_version(T)
        fixed_acu_regret = self.fixed_acu_regret_func(fixed_regret)

        return regret, fixed_regret, acu_regret, fixed_acu_regret, p_value, upper_bound


