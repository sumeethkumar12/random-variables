
#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import mpmath as mp
import scipy 
import matplotlib.pyplot as plt

#if using termux
import subprocess
import shlex
#end if


maxrange=80
maxlim=6.0
x = np.linspace(-maxlim,maxlim,maxrange)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
pdf = [] #declaring pdf list
h = 2*maxlim/(maxrange-1)
#randvar = np.random.normal(0,1,simlen)
#randvar = np.loadtxt('uni.dat',dtype='double')
randvar = np.loadtxt('tri.dat',dtype='double')

for i in range(0,maxrange):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

	
for i in range(0,maxrange-1):
	test = (err[i+1]-err[i])/(x[i+1]-x[i])
	pdf.append(test) #storing the pdf values in a list

def tri_pdf(x):
    if x<0:
        return 1e-5
    elif x>=0 and x<=1:
        return x
    elif x>1 and x<=2:
        return 2-x
    else :
        return 0            
vec_tri_pdf = scipy.vectorize(tri_pdf)

plt.plot(x[0:(maxrange-1)].T,pdf,'o')#numerical
plt.plot(x,vec_tri_pdf(x))# Theory

plt.grid() #creating the grid
plt.xlabel('$x_i$')
plt.ylabel('$p_T(x_i)$')
plt.legend(["Numerical","Theory"])


#if using termux
#plt.savefig('../figs/uni_pdf.pdf')
#plt.savefig('../figs/uni_pdf.eps')
#subprocess.run(shlex.split("termux-open ../figs/uni_pdf.pdf"))
#if using termux
plt.savefig('tri_pdf.png')

#else
#plt.show() #opening the plot window
