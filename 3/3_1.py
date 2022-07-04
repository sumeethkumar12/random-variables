#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import math

#if using termux
import subprocess
import shlex

import scipy
#end if

def cdf(x):
    if x<0:
  	return 0
    else :
        return 1 - math.exp(-x/2)
x = np.linspace(-10,10,50)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list

randvar = np.loadtxt('uni.dat',dtype='double')
for i in range(len(x)):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

V_cdf = scipy.vectorize(cdf)
	
plt.plot(x.T,err,"o")#plotting the CDF
plt.plot(x,V_cdf(x))
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend(["Numerical","Theoritical"])



plt.show() #opening the plot window
