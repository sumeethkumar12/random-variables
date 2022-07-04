#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import mpmath as mp
import scipy

#if using termux
#import subprocess
#import shlex
#end if

def q_func(x):
    return mp.erfc(x/np.sqrt(2))/2
def cdf(x):
    return 1-q_func(x)
    
 maxrange=50
maxlim=4.0
x = np.linspace(-maxlim,maxlim,maxrange)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
#randvar = np.random.normal(0,1,simlen)
#randvar = np.loadtxt('uni.dat',dtype='double')
randvar = np.loadtxt('gau.dat',dtype='double')
#randvar = np.loadtxt('ln.dat',dtype='double')

for i in range(0,maxrange):
    err_ind = np.nonzero(randvar < x[i]) #checking probability condition
    err_n = np.size(err_ind) #computing the probability
    err.append(err_n/simlen) #storing the probability values in a list

vec_gauss_cdf= scipy.vectorize(cdf)

plt.plot(x,err,'o')
plt.plot(x,vec_gauss_cdf(x))#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend(["Numerical","Theory"])

#if using termux
#plt.savefig('../figs/uni_cdf.pdf')
#plt.savefig('../figs/uni_cdf.eps')
#subprocess.run(shlex.split("termux-open ../figs/uni_cdf.pdf"))
#if using termux
#plt.savefig('../figs/gauss_cdf.pdf')
#plt.savefig('../figs/gauss_cdf.eps')
#subprocess.run(shlex.split("termux-open ../figs/gauss_cdf.pdf"))
#else
plt.show() #opening the plot window
