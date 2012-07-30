#include "..\include\Soldier.h"

Soldier::Soldier(){
    power  = 25;
    health = 100;
}

Soldier::Soldier(int pw, int hp=100){
    power  = pw;
    health = hp;
}

Soldier::~Soldier(void){}

int Soldier::GetPw(){
    return power;
}

int &Soldier::GetHp(){
    return health;
}
