#ifndef __SOLDIER_H__
#define __SOLDIER_H__

class Soldier{
private:
    int power;
    int health; //health point

public:
    Soldier();
    Soldier(int pw, int hp);
    ~Soldier();
    int GetPw();
    int &GetHp();
    //int Hp();

friend class Army;
};

#endif // __SOLDIER_H__
