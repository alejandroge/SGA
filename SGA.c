#include <stdio.h>
#include <stdlib.h>

const unsigned short NPARAMS = 2;
const unsigned short NIND = 50;
const unsigned short NBITS[] = {10, 10};
#define LLIMIT -2.048
#define ULIMIT 2.048
double RANGE = ULIMIT - LLIMIT;

#include "INDIVIDUAL-init.h"
#include "POPULATION-init.h"
#include "POPULATION-eval.h"

int main(int argc, char const *argv[]) {
  unsigned short ncbits;
  INDIVIDUAL * ind, * ppltn;

  ppltn = allocPopulation();
  if(ppltn == NULL) return 1;

  // Initialize Individual
  if( initPopulation(ppltn) == 1){
    printf("Cannot initialize individual properly\n");
    return 1;
  }

  EvaluatePopulation(ppltn);
  showPopulation(ppltn);

  return 0;
}
