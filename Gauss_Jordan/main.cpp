//#include <mozg.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


void Print(int I, int J, double** A){
    cout.setf(ios::fixed);
    cout.precision(4);
    for(int i=0;i<I;i++){
        for(int j=0;j<J;j++) cout << A[i][j] << " ";
        cout << endl;
    }
}

int CtrlLine(int n, double* A){
    for(int i=0;i<n;i++){ if(A[i]!=0){return 0;} }
    return -1;
}

int NumberMaxLine(int I, int n, double** A){
	int tmp=I;
	for(int i=I;i<n;i++){ if(fabs(A[i][I])>fabs(A[tmp][I])) {tmp=i;}; }
    return tmp;
}

void SwapLine(int I, int J, int n, double** &A){
    double* tmp = new double [n+1];
    tmp = A[I];
    A[I] = A[J];
    A[J] = tmp;
}

void TransformLine(int I, int J, int n, double** &A){
    double mult=A[J][I]/A[I][I];
    for(int i=I+1;i<n+1;i++) {A[J][i]=A[J][i]-A[I][i]*mult;}
    A[J][I]=0;
}

void ZeroColDown(int I, int n, double** &A){
    for(int j=I+1;j<n;j++){TransformLine(I,j,n,A);}
}

void ZeroColUp(int I, int n, double** &A){
    for(int j=I-1;j>-1;j--){TransformLine(I,j,n,A);}
}

void Jordan(int n, double** &A, double* &X){
    bool flag=false;
    for(int i=0;i<n;i++){
        SwapLine(i,NumberMaxLine(i,n,A),n,A);
        if(CtrlLine(n,A[i]) == -1){flag=true; break;};
        ZeroColDown(i,n,A);
    }
    if(flag){cout << "WTF"<< endl; }
    for(int i=n-1;i>0;i--) {ZeroColUp(i,n,A);}
    for(int i=0;i<n;i++){X[i]=A[i][n]/A[i][i];}
}


int main(){

	int n;
	double** A;
	double* X;

	ifstream InF("1.txt");
	InF >> n;

	X = new double[n];

	A = new double*[n];
	for(int i=0;i<n;i++) A[i]=new double[n+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1;j++) InF >> A[i][j];
	}

	InF.close();

	Print(n, n+1, A);
	cout << " " << endl;

	Jordan(n,A,X);
	//Print(n,n+1,A);
	//cout << endl;
	for(int i=0;i<n;i++)cout << "X" << i+1 << " " << X[i] << endl;
	for(int i=0;i<n;i++) delete A[i];
	delete []X;
	delete []A;
	return 0;
}
