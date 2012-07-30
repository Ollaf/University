#ifndef __RANDOM_H__
#define __RANDOM_H__

#define M1 16807
#define M2 65539
#define Mod 2147483647

#include <vector>

using namespace std;

class Random{
private:
	int gr1, gr2;
	vector<long double> rn;
	long ibm1, ibm2;
public:
	Random(int _gr1, int _gr2);
	~Random();
	long double Rand();
	long double Rand_MAX();
	long int Step();
};

#endif // __RANDOM_H__
