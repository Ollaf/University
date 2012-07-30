#ifndef __ISING2D_H__
#define __ISING2D_H__

#include "Random.h"

#include <math.h>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Ising2D{
private:
	long int L, N, E, M, Spin[128][128];
	long int isum, maxi, istart, count;
	long double T, ecum, e2cum, mcum, m2cum, w[4], e4, e8;
	long int Pre(long int f);
	vector<string> name;
	string type, folder;

public:
	Ising2D(long int _L, long int _maxi, long int _istart, long double _T);
	~Ising2D();
	void Period(long int i, long int j);
	void Accept(long int g, long int f);
	void Data();
	void Output();
	void SetT(long double _T);
	void SetL(long int _L);
	void Modeling(Random R);

	void Out(int step);
	void Model(int step, Random R);
};

#endif // __ISING2D_H__
