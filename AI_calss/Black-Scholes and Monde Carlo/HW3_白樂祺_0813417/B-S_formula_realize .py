#!/usr/bin/env python
# coding: utf-8

# In[9]:


import math 
import numpy as np
from scipy.stats import norm 
import matplotlib.pyplot as plt 

def BisectioniBLS(S,K,T,r,call):
    left = 0.00000001
    right = 1
    while(right-left) > 0.00001 :
        middle = (left+right)/2
        if (blscall(S,K,T,r,middle)-call)*(blscall(S,K,T,r,left)-call)<0 :
            right = middle
        else:
            left = middle
    return (left+right)/2

def blscall(S,K,T,r,vol):
    d1 = (math.log(S/K)+(r+vol*vol/2)*T)/(vol*math.sqrt(T))
    d2 = d1-vol*math.sqrt(T)
    call = S*norm.cdf(d1)-K*math.exp(-r*T)*norm.cdf(d2)
    return call

def MCcall (S, K, T, r, vol, N) : #切成N段
    dt = T/N
    St = np.zeros((N+1))
    St[0] = S
    for i in range(N):
        St[i+1] = St[i]*math.exp((r-0.5*vol**2)*dt + vol*np.random.normal()*math.sqrt(dt))
    return St


# In[10]:


S = 50 
T = 2
K = 40 
r = 0.08
vol = 0.2
bls = blscall(S, K, T, r, vol)
bls


# In[4]:


call_ = 0
N = 100  #每條切成幾段
M = 1000 #發展出幾條線
for i in range(M) :
    Sa = MCcall(S, K, T, r, vol, N)
    plt.plot(Sa)
    if Sa[-1]-K > 0 :
        call_ += (Sa[-1]-K)
print((call_/M)*math.exp(-r*T))


# In[31]:


sum_error = 0
for k in range(10) :
    call = 0
    error = 0
    N = 100  #每條切成幾段
    M = 1000 #發展出幾條線
    for i in range(M) :
        Sa = MCcall(S, K, T, r, vol, N)
        if Sa[-1]-K > 0 :
            call += (Sa[-1]-K)
    error = (call/M)*math.exp(-r*T) - bls
    sum_error += error
    print(error)
print("everage error : ",sum_error/10) 


# In[5]:


N_list = [10, 10, 10, 100, 100, 100, 1000, 1000]
M_list = [10, 100, 1000, 10, 100, 1000, 10, 100]
for a in range(8) :
    sum_error = 0
    for k in range(100) :
        call = 0
        error = 0
        N = N_list[a]  #每條切成幾段
        M = M_list[a] #發展出幾條線
        for i in range(M) :
            Sa = MCcall(S, K, T, r, vol, N)
            if Sa[-1]-K > 0 :
                call += (Sa[-1]-K)
        error = (call/M)*math.exp(-r*T) - bls
        sum_error += error
    print("everage error in N=", N, " , M=", M, " : ",sum_error/100) 


# In[6]:


N_list = [10, 100, 1000, 10, 100, 1000, 10, 100]
M_list = [10, 10, 10, 100, 100, 100, 1000, 1000]
for a in range(8) :
    sum_error = 0
    for k in range(100) :
        call = 0
        error = 0
        N = N_list[a]  #每條切成幾段
        M = M_list[a] #發展出幾條線
        for i in range(M) :
            Sa = MCcall(S, K, T, r, vol, N)
            if Sa[-1]-K > 0 :
                call += (Sa[-1]-K)
        error = (call/M)*math.exp(-r*T) - bls
        sum_error += error
    print("everage error in N=", N, " , M=", M, " : ",sum_error/100) 


# In[13]:


vol = []
S = 16393.16
K_list = [15800, 15900, 16000, 16100, 16200, 16300, 16400, 16500, 16600, 16700, 16800, 16900, 17000, 17100, 17200, 17300, 17400]
T = 14/365
r = 0.00825
call_list = [655, 585, 499, 434, 372, 306, 248, 199, 156, 117, 86, 60, 41, 28.5, 20.5, 14.5, 10]
for i in range(17) :
    K = K_list[i]
    call_price = call_list[i]
    vol.append(BisectioniBLS(S, K, T, r, call_price))
plt.plot(K_list, vol)
vol


# In[ ]:




