#include <iostream>
#include <clocale>

#include <math.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

#include "include/Random.h"
#include "include/Ising2D.h"

using namespace std;

int Log_2(int x);

int main(){
	cout.setf(ios_base::fixed);
	cout.precision(3);
	srand(time(NULL));
	setlocale(LC_ALL, ".ACP");
	int n = 10;

for(int i=0; i<n; i++){

	Random R(rand(),rand());
	long int 	Lmin=8,  Lmax=64;
	long double Tmin=1.5, Tmax=3.55;

	long int 	L = Lmin;
	long double T = Tmin;
	long double h = 0.05;

	while(L<=Lmax){
		while(T<=Tmax){
			Ising2D Ising(L, 100000, 10000, T);
			Ising.Model(Log_2(L),R);
			system("cls");
			cout << "Прогонка " << i << endl;
			cout << "Работа выполнена на ";
			cout << ((double)(Log_2(L)-Log_2(Lmin))+(T-Tmin)/(Tmax-Tmin))*100/(Log_2(Lmax)-Log_2(Lmin)+1) << "%" << endl;
			T+=h;
		}
		T=Tmin;
		L*=2;
	}
}
	//system("pause");
    return 0;
    //2020 мин
}

int Log_2(int x){
	int res = 0;
	while(x!=1){ x/=2; res++; }
	return res;
}
