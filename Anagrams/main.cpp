#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void swap(char &a, char &b)
{
char X=a;
     a=b;
     b=X;
}

int main()
{
	char Word_0[20], Word_1[20], Word_2[20];
	int Len_0, Len_1;
	bool flag,ind=false;
	ifstream InF("Text.txt");



cout << "Vedite slovo, anogrammu kotorogo hotite naiti" << "\n";
cin >> Word_0;
cout << "\n";

Len_0=strlen(Word_0);
//��������� ������ �����..
for (int i=0; i<Len_0; i++)
{
   for (int j=1; j<Len_0; j++)
   {if (Word_0[j-1]>Word_0[j]) swap (Word_0[j-1],Word_0[j]);}
}
//�������������...
while (!InF.eof())
{
   InF >> Word_1;
   Len_1=strlen(Word_1);
// K������� �����
   for(int i=0; i<Len_1; i++)
   {Word_2[i] = Word_1[i];}
// ���������..������ �����..
   if (Len_0 == Len_1)
   {
      for (int i=0; i<Len_1; i++)
	  {
         for (int j=1; j<Len_1; j++)
		 {if (Word_1[j-1]>Word_1[j]) swap (Word_1[j-1],Word_1[j]);}
	  }
// �������������...
// ���������� ������� � ������...
	  flag = true;
      for(int j=0; j<Len_1; j++)
	  {
		  if (!flag) break;
		  if(!(Word_0[j] == Word_1[j])) flag = false;
      }
//���� ����� ������� ...
//������� ��...
	  if (flag)
	  {
		  ind=true;
		  for (int i=0; i<Len_1; i++)
		  {cout << Word_2[i];}
		  cout << "\n";
	  }
   }
}
if(!ind) cout<<"Anogramm ne obnarujeno" << "\n";
cin.get();
cin.get();
return 0;
}
