void EvaluatePopulation(INDIVIDUAL * ppltn);  // Iterates over the array of population
void EvaluateIndividual(INDIVIDUAL * ind);    // Inside here the evaluation function is set

void EvaluatePopulation(INDIVIDUAL * ppltn) {
  unsigned short i;

  for(i=0; i<NIND; i++) {
    EvaluateIndividual(ppltn+i);
  } printf("Population evaluated\n");
}

void EvaluateIndividual(INDIVIDUAL * ind) {
  /*
    Function to evaluate with is 100 (y^2 - x )^2 + (1-y)^2
    Find minimum which is at (x, y) = { 1, 1}
  */
  double aux1, aux2;
  aux1 = (ind->value[1]*ind->value[1]-ind->value[0])*(ind->value[1]*ind->value[1]-ind->value[0]);
  aux2 = (1-ind->value[1])*(1-ind->value[1]);

  ind->fitness = 100*aux1 + aux2;
}
