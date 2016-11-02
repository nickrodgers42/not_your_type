#include <iostream>
#include <string>
#include "tarotCard.h"

using namespace std;

TarotCard::TarotCard()
{
  name = "Unnamed";
  time = "Untimed";
  desc = "Indescribed";
  hp = 0;
  attack = 0;
}

TarotCard::TarotCard(string n, string t, string d, int health, int atck)
{
  name = n;
  time = t;
  desc = d;
  hp = health;
  attack = atck;
}

TarotCard::~TarotCard()
{

}

string TarotCard::getName()
{
  return name;
}

string TarotCard::getDesc()
{
  return desc;
}

string TarotCard::getTime() { return time; }

int TarotCard::getAttack(void) { return attack; }
int TarotCard::getHP(void) { return hp; }


