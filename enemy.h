#ifndef ENEMY
#define ENEMY

#include <iostream>
#include <string>
// #pragma once

using namespace std;

class Enemy
{
private:
  string name, desc, talk;
  int hp, attack;
  bool run;

public:
  Enemy();
  Enemy(string n, string d, string t, int health, int atck, bool r);
  string getName(void);
  string getDesc(void);
  string getTalk(void);
  int getHP(void);
  int getAttack(void);
  void setHP(int i);
  bool getRun(void);
};

#endif
