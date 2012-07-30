#include "../include/Ising2D.h"

Ising2D::Ising2D(long int _L, long int _maxi, long int _istart, long double _T){
	L=_L;
	T=_T;
	maxi=_maxi;
	istart=_istart;
	count=0;
	ecum=0;
	e2cum=0;
	mcum=0;
	m2cum=0;

	for(int i=0; i<L; i++){
		for(int j=0; j<L; j++) Spin[i][j]=1;
	}
	N=L*L;
	E=-2*N;
	M=N;
	e4=exp(-4.0/T);
	e8=e4*e4;
	w[0]=e8; w[1]=1./e8; w[2]=e4; w[3]=1./e4;

	name.push_back("0x0/)");
	name.push_back("2x2/");
	name.push_back("4x4/");
	name.push_back("8x8/");
	name.push_back("16x16/");
	name.push_back("32x32/");
	name.push_back("64x64/");
	name.push_back("128x128/");
	type=".dat";
	folder="Results/";
}

Ising2D::~Ising2D(){}

long int Ising2D::Pre(long int f){
	switch(f){
		case  4: return 0;
		case -4: return 1;
		case  2: return 2;
		case -2: return 3;
	}
}

void Ising2D::Period(long int i, long int j){
	long int l, r, d, u;
	if(i==0) 	l=Spin[L-1][j];
	else 		l=Spin[i-1][j];

	if(i==L-1)	r=Spin[0][j];
	else		r=Spin[i+1][j];

	if(j==0)	d=Spin[i][L-1];
	else		d=Spin[i][j-1];

	if(j==L-1)	u=Spin[i][0];
	else		u=Spin[i][j+1];

	isum=l+d+r+u;
}

void Ising2D::Accept(long int g, long int f){
	Spin[g][f]*=(-1);
	M=M+2*Spin[g][f];
	E=E-2*Spin[g][f]*isum;
}

void Ising2D::Data(){
	ecum+=E;
	e2cum+=(E*E);
	mcum+=fabs(M);
	m2cum+=(M*M);
}

void Ising2D::Output(){
	long double znorm, eav, e2av, sav, s2av, CT, CX;
	znorm=1./(long double)(N*count);
	eav=ecum*znorm;
	e2av=e2cum*znorm;
	sav=mcum*znorm;
	s2av=m2cum*znorm;
	CT=(e2av-(N*eav*eav))/(T*T);
	CX=(s2av-(N*sav*sav))/T;

	ofstream OutF;
	OutF.open("result.html", ios_base::app);

	OutF << "==========================================" << "<br/>" << endl;
	OutF << "Линейный размер решетки =" << L << "<br/>" << endl;
	OutF << "Число шагов Монте-Карло на спин =" << maxi << "<br/>" << endl;
	OutF << "Число начально отбрасываемых конфигураций =" << istart << "<br/>" << endl;
	OutF << "Температура =" << T << "<br/>" << endl;
	OutF << "Средняя энергия на спин =" << eav << "<br/>" << endl;
	OutF << "Средняя намагниченность на спин =" << sav << "<br/>" << endl;
	OutF << "Теплоемкость на спин =" << CT << "<br/>" << endl;
	OutF << "Восприимчивость на спин =" << CX << "<br/>" << endl;
	OutF << "==========================================" << "<br/>" << endl;

	OutF.close();
}

void Ising2D::SetT(long double _T){
	T=_T;
}

void Ising2D::SetL(long int _L){
	L=_L;
}

void Ising2D::Modeling(Random R){
	for(int k=0; k<maxi; k++){
		for(int p=0; p<N; p++){
			long int i=(long int)(L*R.Rand());
			long int j=(long int)(L*R.Rand());
			Period(i,j);
			if((Spin[i][j]*isum)<=0) Accept(i,j);
			else if(R.Rand()<w[Pre(isum*Spin[i][j])]) Accept(i,j);
		}
		if(k>=istart){ Data(); count++; }
	}
	Output();
}

void Ising2D::Out(int step){
	long double znorm, eav, e2av, sav, s2av, CT, CX;
	string s="";
	znorm=1./(long double)(N*count);
	eav=ecum*znorm;
	e2av=e2cum*znorm;
	sav=mcum*znorm;
	s2av=m2cum*znorm;
	CT=(e2av-(N*eav*eav))/(T*T);
	CX=(s2av-(N*sav*sav))/T;

	s=folder+ name[step]+ "E"+ type; ofstream OutE; OutE.open(s.c_str(), ios_base::app);
	s=folder+ name[step]+ "M"+ type; ofstream OutM; OutM.open(s.c_str(), ios_base::app);
	s=folder+ name[step]+ "C"+ type; ofstream OutC; OutC.open(s.c_str(), ios_base::app);
	s=folder+ name[step]+ "X"+ type; ofstream OutX; OutX.open(s.c_str(), ios_base::app);

	OutE << T << "\t" << eav << endl;
	OutM << T << "\t" << sav << endl;
	OutC << T << "\t" << CT << endl;
	OutX << T << "\t" << CX << endl;

	OutE.close();
	OutM.close();
	OutC.close();
	OutX.close();
}

void Ising2D::Model(int step, Random R){
	for(int k=0; k<maxi; k++){
		for(int p=0; p<N; p++){
			long int i=(long int)(L*R.Rand());
			long int j=(long int)(L*R.Rand());
			Period(i,j);
			if((Spin[i][j]*isum)<=0) Accept(i,j);
			else if(R.Rand()<w[Pre(isum*Spin[i][j])]) Accept(i,j);
		}
		if(k>=istart){ Data(); count++; }
	}
	Out(step);
}
