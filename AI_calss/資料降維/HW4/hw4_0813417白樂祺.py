#!/usr/bin/env python
# coding: utf-8

# In[236]:


from sklearn import datasets
import numpy as np
import matplotlib.pyplot as plt  


# In[237]:


iris = datasets.load_iris()
data = iris.data
target = iris.target


# In[263]:


def PCATrain(D) : #D:data R:ratio
    sn, fn = D.shape #列數、行數
    meanv = np.mean(D, axis=0) #axis=0 每一行為一組
    stdv = np.std(D, axis=0)
    D2 = (D - np.matlib.repmat(meanv, sn, 1))/np.matlib.repmat(stdv, sn, 1) 
    C = np.dot(np.transpose(D2), D2) #covariance matrix
    EValue, Evector = np.linalg.eig(C) #求算數值
    EV2 = np.cumsum(EValue)/np.sum(EValue) #EV2為解釋變異的佔比
    print(EV2)
    V = Evector[0:4,0:2]#取前兩維
    new_value = D.dot(V)
    return new_value[:]


# In[264]:


z0 = []
w0 = []
z1 = []
w1 = []
z2 = []
w2 = []
a = PCATrain(data)
for i in range(150):
    if target[i] == 0 :
        z0.append(a[i][0])
        w0.append(a[i][1])
    if target[i] == 1 :
        z1.append(a[i][0])
        w1.append(a[i][1])
    if target[i] == 2 :
        z2.append(a[i][0])
        w2.append(a[i][1])
for i in range(150) :
    plt.plot(z1, w1, '.')
    plt.plot(z0, w0, '.')
    plt.plot(z2, w2, '.')


# In[ ]:




