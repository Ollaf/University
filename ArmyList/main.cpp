#include <iostream>
#include <list>
#include "classes.h"
#include <time.h>
#include <windows.h>
#include <math.h>
//#include <stdlib.h>
using namespace std;

void test();

int main(){



	Fight Battle(7);
	Battle.Start();

    cout << "Hello world!" << endl;
    return 0;
}











void test(){
   list<int> L;
   L.push_back(0);              // Insert a new element at the end
   L.push_front(0);             // Insert a new element at the beginning
   L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place before second argument)
   L.push_back(5);
   L.push_back(6);

   list<int>::iterator i;

   for(i=L.begin(); i != L.end(); ++i) cout << *i << " ";
   cout << endl;
}
