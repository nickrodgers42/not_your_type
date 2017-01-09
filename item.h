#ifndef ITEM
#define ITEM

#include <string>
#include <iostream>
// #pragma once

using namespace std;

class Item
{
private:
  string name, desc;
  int hp, attack;

public:
  Item();
  Item(string, string, int, int);
  ~Item();
  string getName(void);
  string getDesc(void);
  int getHP(void);
  int getAttack(void);
};

#endif