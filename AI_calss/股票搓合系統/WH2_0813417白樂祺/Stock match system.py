#!/usr/bin/env python
# coding: utf-8

# In[6]:


import matplotlib.pyplot as plt
import numpy as np

def long_straddle(ST, X, call, put) :
    return np.maximum(ST-X, 0) - call + np.maximum(X-ST, 0) - put 

def short_straddle(ST, X, call, put) :
    return np.minimum(X-ST, 0) + call + np.minimum(ST-X, 0) + put

def long_strangle(ST, call_X, put_X, call, put) :
    return np.maximum(ST-call_X, 0) - call + np.maximum(put_X-ST, 0) - put

def short_strangle(ST, call_X, put_X, call, put) :
    return np.minimum(call_X-ST, 0) + call + np.minimum(ST-put_X, 0) + put

def long_butterflyspread(ST, put_X_high, put_X_middle, put_X_low, put_high, put_middle, put_low) :
    return np.maximum(put_X_high-ST, 0) - put_high + np.maximum(put_X_low-ST, 0) - put_low + 2*np.minimum(ST-put_X_middle, 0) + 2*put_middle

def short_butterflyspread(ST, call_X_high, call_X_middle, call_X_low, call_high, put_middle, call_low) :
    return np.minimum(call_X_high-ST, 0) + call_high + np.minimum(call_X_low-ST, 0) + call_low + 2*np.maximum(ST-call_X_middle, 0) - 2*put_middle

def long_spread (ST, call_X_1, call_X_2, long, short) :#call1<call2
    return np.maximum(ST-call_X_1, 0)-long + np.minimum(call_X_2-ST, 0)+short

def short_spread (ST, call_X_1, call_X_2, long, short) :#call1>call2
    return np.maximum(ST-call_X_1, 0)-long + np.minimum(call_X_2-ST, 0)+short

def long_call(ST, call_X, call):
    return np.maximum(ST-call_X, 0)-call

def short_put(ST, put_X, put):
    return np.minimum(ST-put_X, 0)+put

def long_put(ST, put_X, put):
    return np.maximum(put_X-ST, 0)-put

def short_call(ST, call_X, call):
    return np.minimum(call_X-ST, 0)+call
#1
ST = np.arange(15000,18000)
plt.plot(ST, short_straddle(ST, 16500, 199, 390), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("short straddle")
plt.savefig("short_straddle.png")
plt.show()

plt.plot(ST, short_strangle(ST, 17400, 15900, 10, 175), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("short strangle1")
plt.savefig("short_strangle1.png")
plt.show()


plt.plot(ST, short_strangle(ST, 16600, 16400, 156, 339), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("short strangle2")
plt.savefig("short_strangle2.png")
plt.show()

plt.plot(ST, long_butterflyspread(ST, 17000, 16500, 16000, 725, 390, 201), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("long butterflyspread1")
plt.savefig("long_butterflyspread1.png")
plt.show()

plt.plot(ST, long_butterflyspread(ST, 17300, 16500, 15900, 1000, 390, 175), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("long butterflyspread2")
plt.savefig("long_butterflyspread2.png")
plt.show()
#3
plt.plot(ST, long_call(ST, 15800, 655), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("long call1")
plt.savefig("long_call1.png")
plt.show()

plt.plot(ST, long_call(ST, 16200, 372), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("long call2")
plt.savefig("long_call2.png")
plt.show()

plt.plot(ST, short_put(ST, 15800, 157), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("short put1")
plt.savefig("short_put1.png")
plt.show()

plt.plot(ST, short_put(ST, 16200, 265), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("short put2")
plt.savefig("short_put2.png")
plt.show()

plt.plot(ST, long_spread(ST, 16000, 16300, 499, 299), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("long spread1")
plt.savefig("long_spread1.png")
plt.show()

plt.plot(ST, long_spread(ST, 15800, 16300, 655, 299), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("long spread2")
plt.savefig("long_spread2.png")
plt.show()

#2
plt.plot(ST, short_put(ST, 16300, 299)+long_call(ST, 16300, 306), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("posistive_line")
plt.savefig("posistive_line.png")
plt.show()

plt.plot(ST, long_put(ST, 16400, 339)+short_call(ST, 16400, 248), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("negetive_line")
plt.savefig("negetive_line.png")
plt.show()

plt.plot(ST, long_put(ST, 16400, 339)+short_call(ST, 16400, 248)+short_put(ST, 16300, 299)+long_call(ST, 16300, 306), "-", [15000,18000], [0,0], "--")
plt.xlabel("St")
plt.ylabel("profit")
plt.title("arbitrage")
plt.savefig("arbitrage.png")
plt.show()


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




