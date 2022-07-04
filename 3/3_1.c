
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int main(){
  FILE* fp;
  FILE* fp1;
  double v = 0.0;
  double u = 0.0;
  fp = fopen("uni.dat","r");
  fp1 = fopen("ray.dat","w");
  while(fscanf(fp,"%lf",&u)!=EOF){
     v = -2*log(1-u);
     fprintf(fp1,"%lf\n",v);
    }
    fclose(fp);
    fclose(fp1);

   
   return 0;


