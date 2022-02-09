
import numpy as np
import math

data = np.load('data.npy')[0:500]#取前500筆資料
complete_data = np.load('data.npy')

def MAE(real, predict):
    print("e : ",np.mean(abs(real[:len(predict)]  - predict)))
def nonlinear_coef(gene) : #先利用基因求出對應的數值，不會需要用到線性變數                                                                                                     
    tc = np.sum(2**np.arange(16)*gene[0:16])*0.0002289 + 500
    beta = np.sum(2**np.arange(16)*gene[16:32])*0.000001526 +0.3 #0.3~0.4
    omega  = np.sum(2**np.arange(16)*gene[32:48])*0.000018367 + 4#4~5.12
    phi = np.sum(2**np.arange(16)*gene[48:64])*(2/65535)*(math.pi)
    return tc, beta, omega, phi
def linear_coef(T, tc, beta, omega, phi, data) :#已知4個非線性參數了，現在可以利用線性求出3個線性參數
    A = np.zeros((data.shape[0], 3)) 
    for i in range(list(data.shape)[0]):
        A[i, 0] = 1
        A[i, 1] = (tc-T[i])**beta
        A[i, 2] = ((tc-T[i])**beta)*np.cos(omega*np.log(tc-T[i])+phi)
    x = np.linalg.lstsq(A, data, rcond=None)[0]
    return x[0], x[1], x[2]   
def predict_result(T, tc, beta, omega, phi, A, B, D) :
    return A + B*((tc-T)**beta) + D*((tc-T)**beta)*np.cos(omega*np.log(tc-T)+phi)

N = 10000#原始一萬人
G = 4#繁衍10代
survive_rate = 0.001 
survive = round(N*survive_rate)
mutation = round(N*64*0.001)
pop = np.random.randint(0, 2, (N, 64))#每個人的基因
fit = np.zeros((N,1))
T = np.array(range(list(data.shape)[0]))#所有時間序列 ==> shape對應到data (上課的例子是無序的，現在的標準答案是data)

for generation in range(G) :
    for i in range(N) :
        tc, beta, omega, phi = nonlinear_coef(pop[i,:])#求出tc beta omega phi
        A, B, D = linear_coef(T, tc, beta, omega, phi, data)
        fit[i] = np.mean(abs(predict_result(T, tc, beta, omega, phi, A, B, D)-data))#越小越適合
    sortf = np.argsort(fit[:,0])
    pop = pop[sortf,:]
    for i in range(survive,N) :
        fid = np.random.randint(0,survive)
        mid = np.random.randint(0,survive)
        while fid == mid : 
            mid = np.random.randint(0,survive)
        mask = np.random.randint(0,2,(1,64))
        son = pop[mid,:]
        father = pop[fid ,: ]
        son[mask[0,:]==1] = father[mask[0,:]==1]
        pop[i,:] = son
    for i in range(mutation) :
        mutation_people = np.random.randint(0,N)#選哪一個人要突變
        mutation_gene = np.random.randint(0,64) #選那一個人的哪一個基因要突變
        pop[mutation_people, mutation_gene] = 1-pop[mutation_people, mutation_gene]#變


for i in range(N) :
    tc, beta, omega, phi = nonlinear_coef(pop[i,:])#求出tc beta omega phi
    A, B, D = linear_coef(T, tc, beta, omega, phi, data)
    fit[i] = np.mean(abs(predict_result(T, tc, beta, omega, phi, A, B, D)-data))#越小越適合
sortf = np.argsort(fit[:,0])
pop = pop[sortf,:]
tc, beta, omega, phi = nonlinear_coef(pop[0,:])
A, B, D = linear_coef(T, tc, beta, omega, phi, data)
C = D/B
print("tc : ", tc)
print("beta : ", beta)
print("omega : ",omega)
print("phi : ",phi)
print("A B C : ",A, B, C)
import matplotlib.pyplot as plt
plt.plot(range(600), complete_data)
predict = []
for i in range(500) :
    predict.append(A+B*((tc-T[i])**beta)+B*C*(((tc-T[i])**beta)*np.cos(omega*np.log(tc-T[i])+phi)))
plt.plot(T, predict)
MAE(data, predict)





