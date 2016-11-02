#include <string>
#include <iostream>
#pragma once

using namespace std;

class TarotCard
{
private:
  string name, time, desc;
  int hp, attack;

public:
  TarotCard();
  TarotCard(string, string, string, int, int);

  string getDesc();
  string getName();
  string getTime();
  int getHP(void);
  int getAttack(void);

};