#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Animal{
private:
	string name;
public:
	Animal(string _name){name=_name;}
	virtual void Say()=0;
	string GetName(){return name;}
};

class Cat:public Animal{
public:
	Cat(string _name):Animal(_name){}
	void Say(){ cout << "Meow, my name is " << GetName() << " , Meow" << endl; }
};

class Dog:public Animal{
public:
	Dog(string _name):Animal(_name){}
	void Say(){cout << "Woof, my name is " << GetName() << " , Woof, Woof" << endl;}
};

int main(){
	vector<Animal*> A;

	A.push_back(new Cat("Barsik"));
	A.push_back(new Cat("Murka"));
	A.push_back(new Dog("Bobik"));
	A.push_back(new Cat("Red"));
	A.push_back(new Dog("Pushok"));
	A.push_back(new Dog("Mukhtar"));

	for(int i=0; i<A.size(); i++) A[i]->Say();
	
system("pause");
return 0;
}