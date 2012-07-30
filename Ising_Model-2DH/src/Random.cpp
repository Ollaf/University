#include "../include/Random.h"

Random::Random(int _gr1, int _gr2){
	gr1=_gr1; gr2=_gr2;
	ibm1=2*gr1+1;
	for(int i=0; i<256; i++){
		ibm1*=M1;
		if(ibm1<0) ibm1+=(Mod+1);
		rn.push_back(ibm1/(double)Mod);
	}
}

Random::~Random(){}

long double Random::Rand(){
	long double r;
	long int k;
	ibm2=2*gr2+1;
	ibm2*=M2;
	ibm1*=M1;

	if(ibm2<0) ibm2+=(Mod+1);
	k=ibm2/8388608+1;
	r=rn[k];
	if(ibm1<0) ibm1+=(Mod+1);
	rn[k]=ibm1/(double)Mod;

	return r;
}

long double Random::Rand_MAX(){
	return 1.0;
}

long int Random::Step(){
	long double a=Rand();
	int count =0;
	do{ count++; }while(a!=Rand());
	return count;
}
