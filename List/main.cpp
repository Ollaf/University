#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;


struct ListElem{
           int info;
           ListElem* next;
           ListElem(int x, ListElem *nxt)
		   {info=x; next=nxt;}
    };


void InsertElem(ListElem *& p, int x){
    ListElem *tmp = new ListElem(x, p->next);
	p->next = tmp;
    p = p->next;
};

void Start(ListElem *& p_1,ListElem *& p_2){
	 p_1=p_2->next;
};


int main(){

	int x,par=10;
	ListElem * buf;
	ListElem * cur;
	ifstream InF("Date.dat");


	buf = new ListElem(0,0);
	buf->next = buf;

	Start(cur,buf);

while (par!=5){
    system ("cls");
		cout << "Vvedite nomer operacii so Spiskom" << "\n";
		cout << "1) - Esli hotite shitat Spisok is faila" << "\n";
		cout << "2) - Esli hotite dobavit element" << "\n";
		cout << "3) - Esli hotite vstst v nachalo Spiska" << "\n";
		cout << "4) - Esli hotite raspechatat' Spisok" << "\n";
		cout << "5) - Esli hotite ostavit v pokoe Spisok" << "\n";
		cin >> par;
		cout << "\n";

switch(par){
	case 1:{
		while (!InF.eof())
			{ InF >> x; InsertElem(cur,x); }
		cout << "Gotovo" << "\n";
        system("pause");
        break;
	}
	case 2:{
		cout << "Vvedite element (type = int), kotoryi nado dobavit v spisok" << "\n";
        cin >> x;
        InsertElem(cur,x);
        cout << "Gotovo" << "\n";
        system("pause");
        break;
	}
    case 3:{
		Start(cur,buf);
		cout << "Gotovo" << "\n";
		system("pause");
		break;
	}
	case 4:{
		Start(cur,buf);
		while ( cur->next!=buf->next ){
                cout << cur->info << endl;
                cur = cur->next;
		}
		cout << "Gotovo" << "\n";
		system("pause");
		break;
	}
	case 5: { break; }
	default :{cout << "Vy oshiblis komandoi...";}
}
}
//Удаляем список
cur = buf -> next;
ListElem *p = cur;
	while(p!=buf){
		buf->next = p->next;
		delete p;
		p = buf->next;
	}
//Закрываем файл
InF.close();

delete cur;
delete buf;
system("pause");
return 0;
}
