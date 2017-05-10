int roulette(INDIVIDUAL *ind);
unsigned short ** rouletteSelection(INDIVIDUAL *ind, unsigned short ** Crosstable);

unsigned short ** rouletteSelection(INDIVIDUAL *ind, unsigned short ** Crosstable) {
    int i,j;
    if(FLAG==0){
        Crosstable = (unsigned short**)malloc((NIND/2)*sizeof(unsigned short*));
        for(i=0;i<NIND/2;i++)
            Crosstable[i] = (unsigned short*)malloc(2*sizeof(unsigned short));
        FLAG=1;
    }

    for(i=0;i<NIND/2;i++)
        for(j=0;j<2;j++)    Crosstable[i][j]=roulette(ind);


    /*for(i=0;i<NIND/2;i++){
      for(j=0;j<2;j++)    printf("\t%d", Crosstable[i][j]);
      printf("\n");
    }*/
    return Crosstable;
}

int roulette(INDIVIDUAL *ind) {
    int i;
    /*
    if(FLAG==0){
        Crosstable = (unsigned short**)malloc((NIND/2)*sizeof(unsigned short*));
        for(i=0;i<NIND/2;i++)
            Crosstable[i] = (unsigned short*)malloc(2*sizeof(unsigned short));
        FLAG=1;
    }
    */
    float fT=0, nrand, Linf=0, Lsup;
    float arraySltn[NIND];
    for(i=0;i<NIND;i++) fT+=ind[i].fitness;
    for(i=0;i<NIND;i++){
        arraySltn[i]=(1-ind[i].fitness/fT)/(double)(NIND-1);
    }
    nrand=rand()/(double)RAND_MAX;
    //nrand=rand()%1000001;
    //nrand/=1000000;
    for(i=0;i<NIND;i++){
        Lsup=Linf+arraySltn[i];
        if(nrand>Linf && nrand<=Lsup) return i;
        Linf=Lsup;
    }
}
