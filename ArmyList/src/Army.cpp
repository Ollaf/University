#include "..\include\Army.h"


Army::Army(string A_name, int n, int s){

    for(int i=0; i<n; i++){
        Soldier S;
        S=Soldier((rand()%30)+1,(rand()%100)+1);
        A.push_back(S);
    }
    ArmyName=A_name;
    Side=s;
}

Army::~Army(){A.clear();}

list<Soldier>& Army::GetArmy(){
	return A;
}

int Army::ArmyPw(){
	list<Soldier>::iterator AIter; // итератор армии(списка)
	int PW=0;
	for(AIter=A.begin(); AIter!=A.end(); AIter++){
		//if(AIter->GetHp())
		PW+=AIter->GetPw();
	} return PW;
}

void Army::SetSide(int s){
    Side=s;
}

string Army::GetName(){
	return ArmyName;
}

int Army::GetSide(){
    return Side;
}

void Army::Delete(){
	//A.remove_if(f);
}
