#ifndef __ARMY_H__
#define __ARMY_H__

#include "Soldier.h"
#include <list>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Army{
private:
    int Side;          // Сторона армии
    string ArmyName;   // Название армии
	list<Soldier> A;   // Состав армии

protected:
    Army();

public:
    Army(string A_name, int n, int s);
    ~Army();
    int ArmyPw();
    list<Soldier>& GetArmy();
    void SetSide(int s);
    int GetSide();
    string GetName();
    void Delete();

friend class Soldier;
};

#endif // __ARMY_H__
