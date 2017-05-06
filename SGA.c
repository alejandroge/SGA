#include <stdio.h>
#include <stdlib.h>

const unsigned short NPARAMS = 2;
const unsigned short NIND = 1;
const unsigned short NBITS[] = {2, 4};
#define LLIMIT 0
#define ULIMIT 10
double RANGE = ULIMIT - LLIMIT;

#include "INDIVIDUAL-init.h"

int main(int argc, char const *argv[]) {
  unsigned short ncbits;
  INDIVIDUAL * ind;

  ind = allocIndividual();
  if(ind == NULL) return 1;

  // Initialize Individual
  if( initIndividual(ind) == 1){
    printf("Cannot initialize individual properly\n");
    return 1;
  }
  return 0;
}
