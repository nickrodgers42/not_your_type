#ifndef PLAYER
#define PLAYER
// #pragma once

#include<iostream>
#include<string>
#include"item.h"

using namespace std;

class Player
{
private:
  string name;
  int hp;
  int attack;
  int lives;
  Item inventory[5];

public:
  Player();
  Player(string n, int health, int atck);
  int getHP(void);
  void setHP(int i);
  int getAttack(void);
  void setAttack(int a);
  void getStats(void);
  void equipItem(Item i);

};
#endif