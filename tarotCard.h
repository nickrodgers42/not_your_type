#ifndef TAROT_CARD
#define TAROT_CARD

#include <string>
#include <iostream>
// #pragma once

using namespace std;

class TarotCard
{
private:
  string name, time, desc;
  int hp, attack;
public:
  TarotCard();
  TarotCard(string n, string d, string t, int hp, int atck);
  ~TarotCard();

  string getDesc();
  string getName();
  string getTime();
  int getHP(void);
  int getAttack(void);

};

#endif