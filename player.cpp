#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player::Player()
{
  name = "No Name";
}

Player::Player(string n, int health, int atck)
{
  name = n;
  hp = health;
  attack = atck;
  lives = 3;
}

int Player::getHP(void)
{
  return hp;
}

void Player::setHP(int i)
{
  hp = i;
}

int Player::getAttack(void)
{
  return attack;
}

void Player::setAttack(int a)
{
  attack = a;
}

void Player::getStats(void)
{
  std::cout << "HP: " << hp << std::endl;
  std::cout << "Attack Power: " << attack << std::endl;
  std::cout << "Lives: " << lives << std::endl;
}