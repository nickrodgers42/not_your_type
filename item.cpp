#include <iostream>
#include <string>
#include "item.h"

using namespace std;

Item::Item()
{
  name = "Unnamed Item";
  desc = "Undescribed";
  hp = 0;
  attack = 0;
}

Item::Item(string n, string d, int health, int atck)
{
  name = n;
  desc = d;
  hp = health;
  attack = atck;
}

string Item::getName(void)
{
  return name;
}

string Item::getDesc(void) { return desc; }

int Item::getHP(void) { return hp; }

int Item::getAttack(void) { return attack; }