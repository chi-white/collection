#!/usr/bin/env python
# coding: utf-8

# In[310]:


import numpy as np
import random
import math
import matplotlib.pyplot as plt


# In[242]:


def update_lambda(S, lambda_bar, delta, arm, lambda_, driver) :
    if S[driver][arm] <= 1 :
        lambda_[driver][arm] = 1
    else :
        lambda_[driver][arm] = (2 * lambda_bar[driver][arm] * math.log(delta / 2, 10) / S[driver][arm] )**0.5 + ( 7 * math.log(2/delta, 10) ) / ( 3 * (S[driver][arm] - 1) )

def update_lambda_bar(loss_matrix, S, arm, lambda_bar) :
    if S[driver][arm] <= 1 :
        lambda_bar[driver][arm] = 0
    else :
        for i in range(int(S[driver][arm])-1) :
            lambda_bar[driver][arm] += ((loss_matrix[driver][i][arm] - loss_matrix[driver][int(S[driver][arm]-1)][arm])**2)/(S[driver][arm]*(S[driver][arm]-1))


def update_mu_bar(S, arm, t, driver, loss_matrix, mu_bar) :
    S[driver][arm] += 1
    loss_sum = 0
    for i in range(t+1) :
        loss_sum += loss_matrix[driver][i][arm]
    mu_bar[driver][arm] = loss_sum/S[driver][arm]
    
    
def select_arm(driver, mu_bar, lambda_) :
    temp = mu_bar[driver]-lambda_[driver]
    if len(np.unique(temp)) == 1:
        return random.randrange(3)
    if len(np.unique(temp)) == 2:
        if temp[0] == temp[1] :
            return random.randrange(2)
        if temp[0] == temp[2] :
            if random.randrange(2) == 0 :
                return 0
            return 1
        if temp[1] == temp[2] :
            return random.randrange(2)+1
    return list(temp).index(min(temp))

def loss_cul(human_acu) :
    loss_feeback = [0,0,0]
    for i in range(len(human_acu)) :   
        if i == 0 : 
            loss_feeback[i] = human_acu[i] * 2
        elif i == 1 :
            loss_feeback[i] = human_acu[i] + 1
        elif i == 2 :
            loss_feeback[i] = human_acu[i]**2
    return loss_feeback

def update_loss_matrix(driver, t, arm, loss) :
    loss_matrix[driver][t][arm] = loss


# In[469]:


trend = []
for B in range(1, 101) :
    drivers = 8
    K = 3      
    t = B
    T = round(100/t)*t
    rounds = round(T/t)
    S = np.zeros((drivers, K))
    mu_bar = np.zeros((drivers, K))
    lambda_bar = np.zeros((drivers, K))
    lambda_ = np.ones((drivers, K))
    loss_matrix = np.zeros((drivers, t, K))
    human_acu = np.zeros((1,K))
    temp_record = np.zeros((1,drivers))
    delta = 7
    picture_show = []
    drivers_cost = np.zeros((drivers, T))
    for i in range(rounds) :
        S = np.zeros((drivers, K))
        mu_bar = np.zeros((drivers, K))
        lamda_bar = np.zeros((drivers, K))
        lambda_ = np.ones((drivers, K))
        loss_matrix = np.zeros((drivers, t, K))
        human_acu = [0, 0, 0]
        temp_record = [0, 0, 0, 0, 0, 0, 0, 0]
        for j in range(t) :
            show = []
            human_acu = [0, 0, 0]
            for driver in range(drivers) :
                arm = select_arm(driver, mu_bar, lambda_)
                temp_record[driver] = arm
                human_acu[arm] += 1
                show.append(arm)
            loss_feeback = loss_cul(human_acu)
            picture_show.append(sum(loss_feeback))
            for driver in range(drivers) :
                drivers_cost[driver][i*t+j] = loss_feeback[temp_record[driver]] ##
                update_loss_matrix(driver, j, temp_record[driver], loss_feeback[temp_record[driver]])
                update_mu_bar(S, temp_record[driver], j, driver, loss_matrix, mu_bar)
                update_lambda_bar(loss_matrix, S, temp_record[driver], lambda_bar)
                update_lambda(S, lambda_bar, delta, temp_record[driver], lambda_, driver)
    trend.append(sum(picture_show)/8)

plt.figure(figsize=(20, 10))    
plt.plot(range(1, 101), trend)
plt.xticks(range(0, 101, 10))
plt.title("Relation between B and average loss")
plt.xlabel('B')
plt.ylabel('everage loss')
# for driver in range(drivers) :
#     plt.figure(figsize=(60, 20))
#     plt.subplot(2, 4, driver+1)
#     plt.plot(range(100), drivers_cost[driver])
#     for i in range(1, 11) :
#         plt.plot([i*10-1,i*10-1], [0, 40], color='red', linestyle=':')
#     plt.xlabel('T')
#     plt.ylabel('Loss')
#     plt.yticks(range(0, 40, 1))
#     plt.xticks(range(0, 101, 10))
#     plt.title("driver" + str(driver))

# plt.figure(figsize=(20,10))
# plt.plot(range(100), np.array(picture_show)/8)
# plt.plot([0,100], [2.6,2.6])
# for i in range(1, rounds+1) :
#     plt.plot([i*t-1,i*t-1], [0, 4], color='red', linestyle=':')
# plt.xlabel('T')
# plt.ylabel('everage loss')
# plt.yticks(range(0, 4, 1))
# plt.xticks(range(0, 101, 10))
# plt.title("B="+str(t)+", Average Loss Diagram")
# plt.show()
# print(sum(picture_show)/8)

