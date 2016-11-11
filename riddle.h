#ifndef RIDDLE
#define RIDDLE

#include <iostream>
#include <string>

using namespace std;

class Riddle
{
private:
  string question, answer;

public:
  Riddle();
  Riddle(string q, string a);
  ~Riddle();
  string getQuestion(void);
  string getAnswer(void);
  bool giveAnswer(string a);
};

#endif