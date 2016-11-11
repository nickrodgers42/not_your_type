#ifndef PLAYER
#define PLAYER
// #pragma once

#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
  string name;
  int hp;
  int attack;
  int lives;

public:
  Player();
  Player(string n, int health, int atck);
  int getHP(void);
  void setHP(int i);
  int getAttack(void);
  void setAttack(int a);
  void getStats(void);
};
#endif