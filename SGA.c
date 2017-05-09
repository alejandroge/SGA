#include <stdio.h>
#include <stdlib.h>

const unsigned short NPARAMS = 2;
const unsigned short NIND = 50;
const unsigned short NBITS[] = {10, 10};
#define LLIMIT -2.048
#define ULIMIT 2.048
double RANGE = ULIMIT - LLIMIT;
#define GLIMIT 10

#include "INDIVIDUAL-init.h"
#include "POPULATION-init.h"
#include "POPULATION-eval.h"

int main(int argc, char const *argv[]) {
  unsigned short nGeneration = 1;
  INDIVIDUAL * ppltn, * bestInd;

  ppltn = allocPopulation();
  if(ppltn == NULL) return 1;

  // Initialize Population
  if( initPopulation(ppltn) == 1){
    printf("Cannot initialize individual properly\n");
    return 1;
  }

  // EvaluatePopulation returns a pointer to the better individual of the population
  bestInd = EvaluatePopulation(ppltn);
  // showPopulation(ppltn);

  printf("\nBest Individual: \n");
  showGenes(bestInd);
  showFitness(bestInd);
  // Stop condition
  while(nGeneration < GLIMIT) {
    nGeneration++;
  }



  return 0;
}
