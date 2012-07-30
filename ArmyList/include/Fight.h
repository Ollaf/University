#ifndef __FIGHT_H__
#define __FIGHT_H__

#include <list>
#include "Army.h"
#include "Soldier.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

class Fight{
private:
	//������� ���� �� ��������� ��� � ������
    vector<Army> F; // ����� �����
    int * Agr[100]; // ���
    int GetAgr(int idx, int &pos);

    void Print(int i_1, int size_1, int i_2, int size_2);

public:
    Fight(int n);// n-����� �����
    ~Fight();
    void Atack(int pos, int& pw);
    void SetAgr();
    void ChAgr();
    void AddArmy(Army &A);
    bool Battle();
    int Start();

friend class Army;
};

#endif // __FIGHT_H__
