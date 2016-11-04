#include <iostream>
#include <string>
#include "riddle.h"

using namespace std;

Riddle::Riddle()
{
  question = "No Question";
  answer = "No Answer";
}

Riddle::Riddle(string q, string a)
{
  question = q;
  answer = a;
}

Riddle::~Riddle()
{

}

string Riddle::getQuestion(void) { return question; }

string Riddle::getAnswer(void) { return answer; }

bool Riddle::giveAnswer(string a)
{
  if (answer == a)
  {
    return true;
  }
  else
    return false;
}