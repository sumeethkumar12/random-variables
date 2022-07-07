
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int main(){

  // Generating two files of uniform random numbers
    uniform("uni1.dat",1000000);

    uniform("uni2.dat",1000000);
  // Generating triangular distribution random numbers in tri.dat file.
    triangular("tri.dat","uni1.dat","uni2.dat",1000000);

    return 0;
    
}
