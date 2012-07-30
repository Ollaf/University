#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human{
private:
    string name;
public:
    Human(string _name_){name = _name_;}
    virtual void Print()=0;
};

class Tool{
public:
    virtual void Print()=0;
};

class Soldier:public Human{
    string rang;
public:
    Soldier(string _name_, string _rang_):Human(_name_){
        rang = _rang_;
    }
    void Print(){cout << "Soldier " << endl;}
};

class Scientist:public Human{
    string science;
public:
    Scientist(string _name_, string _science_):Human(_name_){
        science = _science_;
    }
    void Print(){cout << "Scientist " << endl;}
};

class Pen:public Tool{
    string color;
public:
    Pen(string _color_):Tool(){
        color = _color_;
    }
    void Print(){cout << "Pen " << endl;}
};

class Gun:public Tool{
    string type;
public:
    Gun(string _type_):Tool(){
        type = _type_;
    }
    void Print(){cout << "Gun " << endl;}
};

class AbsFactory{
public:
    virtual Human* MakeHuman()=0;
    virtual Tool*  MakeTool() =0;
};

class Voencomat:public AbsFactory{
    Human* MakeHuman(){
        string name, rang;
        cin >> name;
        cin >> rang;
        return new Soldier(name, rang);
    }

    Tool* MakeTool(){
        return new Gun("type");
    }
};

class Univer:public AbsFactory{
    Human* MakeHuman(){
        string name, science;
        cin >> name;
        cin >> science;
        return new Scientist(name, science);
    }

    Tool* MakeTool(){
        return new Pen("color");
    }
};

int main(){

    vector<AbsFactory*> v(2);

    v[0]= new Voencomat;
    v[1]= new Univer;

    for(int i=0; i<2; i++){
        Human* H=v[i]->MakeHuman();
        Tool*  T=v[i]->MakeTool();
        H->Print();
        T->Print();
    }

    cout << "Hello world!" << endl;
    return 0;
}
