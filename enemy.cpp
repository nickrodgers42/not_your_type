#include <iostream>
#include <string>
#include "enemy.h"

Enemy::Enemy()
{
  name = "No Name";
  desc = "No Description";
  talk = "...";
  hp = 0;
  attack = 0;
  run = true;
}

Enemy::Enemy(string n, string d, string t, int health, int atck, bool r)
{
  name = n;
  desc = d;
  talk = t;
  hp = health;
  attack = atck;
  run = r;
}

string Enemy::getName(void) { return name; }

string Enemy::getDesc(void) { return desc; }

string Enemy::getTalk(void) { return talk; }

int Enemy::getHP(void) { return hp; }

void Enemy::setHP(int i) { hp = i; }

int Enemy::getAttack(void) { return attack; }

bool Enemy::getRun(void) { return run; }