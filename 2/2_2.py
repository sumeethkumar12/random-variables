
#
#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import math

def q(x):
    return(math.erfc(x/math.sqrt(2)))/2.0
     

x = np.linspace(-4,4,30)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
err2=[]
#randvar = np.random.normal(0,1,simlen)
randvar = np.loadtxt('gau.dat',dtype='double')

#randvar = np.loadtxt('gau.dat',dtype='double')
for i in range(0,30):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list
for i in range(len(x)):
    c=q(-x[i])
    err2.append(c)
plt.plot(x.T,err,'o')	
plt.plot(x.T,err2)#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')


plt.show() #opening the plot window
