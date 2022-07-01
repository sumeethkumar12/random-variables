
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int  main(void) //main function begins
{
 
//Uniform random numbers
//uniform("uni.dat", 1000000);

//Gaussian random numbers
//gaussian("gau.dat", 1000000);

//Mean of gaussian
printf("%lf\n",mean("gau.dat"));

//Variance of gaussian
printf("%lf",variance("gau.dat"));

return 0;
}
