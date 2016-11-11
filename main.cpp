#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector> 
#include <stdio.h>
#include "tarotCard.h"
#include "item.h"
#include "enemy.h"
#include "riddle.h"
#include "player.h"

using namespace std;

void findItem(Item i);
void equipItem(Item i);
void fightEnemy(Enemy e);
void printTitleScreen(void);
void playerDeath(void);
void playAg(void);
void basement(void);
bool ridAnswer(Riddle r);

vector<TarotCard> cards(3);
char playA;
char lean;
bool playAgain = true;
string beast = "THE BEWILDERBEAST: AN AIRPLANE WITH 7 FISH HEADS";

int userAttack = 8;
int userHP = 50;

Riddle turkey("Why is a sea anemone like a turkey", "death");
Riddle deep("Before the Marianas Trench was discovered in 1875, what was the deepest place on Earth?", "marianas");
Riddle bury("Why is it illegal to bury someone living in one state in a different state", "alive");
Riddle teethPuck("What's round, black, and bad for your teeth?", "puck");
Riddle sphynx[4] = { turkey, deep, teethPuck, bury };
int riddleNum = rand() % 4;
string answer;

Enemy toupee("Hideous, Sentient Toupee", "A wild mass of hair resembling a certain presidential candidate's hairpiece.", "YUUUGE", 24, 4, false);
Enemy giraffe("Duck-Sized Giraffe", "A giraffe the size of a duck", "What sound do giraffes even make? Moo???", 32, 6, false);
Enemy train("Scary Toy Train with a Laser Pointer", "The train waives its laser pointer around. It's strangely off-putting.", "\"I think I can, I think I can...DEFEAT YOU!", 32, 6, false);
Enemy puck("Malicious hockey puck", "A hockey puck filled with all the agression and testosterone of hockey. Too bad it can't really move on its own.", "The hockey puck does not speak.", 32, 6, false);
Enemy teeth("Teeth", "The tooth fairy is going to have a bad time with this one.", "*chatering*", 40, 8, false);
Enemy cannibal("Acutal Cannibal Shia Le BUFF", "A buff cannibal repeatedly shouting \"DO IT\"", "JUST DO IT", 30, 5, false);

Item mug("Co-Worker's coffee Mug", "I hate mondays is printed in a large black font. \nCome to think of it, your co-worker does hate mondays. \nWhat an honest mug. Otherwise unhelpful.", 0, 0);
Item grenade("Holy Hand Grenade of Antioch", "Pull the pin and count to THREE. Not two, not four, three.", 0, 8);
Item towel("A Towel", "The Ultimate Utility!", 12, 12);
Item meme("Me_irl meme", "An image deserving a lighthearted chuckle. Good for the soul.", 8, 0);

int main(void)
{
  char door;
  char trick;
  char trapStairs;

  char pause = ' ';
  char spanishN = 164;

  string pa = "Past Influences";
  string pr = "Present Influences";
  string fu = "Future Influences";

  TarotCard harambe("Harambe", pa, "Our lord and saviour. He is a gentle, protecting, guiding force", 2, 0);
  TarotCard sewer("Detroit Sewers", pa, "Gross, smelly, even worse than Detroit City. Unnavigable", -2, 0);
  TarotCard dog("Neighbor's dog", pr, "Chases his tail and likes to bring you random left shoes", 0, 2);
  TarotCard eyeball("Eyeball Salad", pr, "Creepy and squishy, eyeball salad stares judgingly into your soul", 0, -2);
  TarotCard theVoid("The Void", fu, "Always there for you, practicing active listening when you scream into it. True friend.", 0, 0);
  TarotCard candy("Melted Candy", fu, "A huge disappointment and a bigger mess. You have a swimming pool of it.", 0, 0);


  TarotCard past[2] = { harambe, sewer };
  TarotCard present[2] = { dog, eyeball };
  TarotCard future[2] = { theVoid, candy };



  srand(time(0));

  int pastCard = rand() % 2;
  int presCard = rand() % 2;
  int futCard = rand() % 2;

  cards[0] = past[pastCard];
  cards[1] = present[presCard];
  cards[2] = future[futCard];

  /*
  cout << "Testing the tarot cards:" << endl;
  cout << cards[0].getName() << "\n" << cards[0].getTime() << "\n" << cards[0].getDesc() << endl;
  cout << cards[1].getName() << "\n" << cards[1].getTime() << "\n" << cards[1].getDesc() << endl;
  cout << cards[2].getName() << "\n" << cards[2].getTime() << "\n" << cards[2].getDesc() << endl;
  */
  while (playAgain)
  {

    printTitleScreen();
    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nWelcome to the Game\n\nPress enter to continue:\n--";
    cin.get();
    cout << endl;
    cout << "You're in a dark room! Where are you? How did you get here? Why are you here?"
      "\nWha-What is that smell, an old bologna and peanut butter sandwich?"
      "\n\nNobody knows!"
      "\n\nThe lights come on, which is fortunate, and you find a weird old lady sitting in the middle of the room, chanting."
      "\nYou also find that she's the source of the smell...which is less fortunate."
      "\nShe keeps chanting as you approach her. "
      "\n\n\"Your fate, my deck, forsees for yards.\""
      "\n\"Your future, here, told by my cards.\""
      "\n\n\"Ok lady,\"  You say. \"I'll bite.\""
      "\nYou take the tarot cards from her as she tries to shove them down the back of your shirt."
      "\n\nThey are : " << endl;

    for (int i = 0; i < 3; i++)
    {
      cout << cards[i].getName() << "\n" << cards[i].getTime() << "\n" << cards[i].getDesc() << endl << endl;
    }

    cout << "[Press enter to continue]" << endl;
    cin.get();

    cout << "You walk away from the weirdo before she has a chance to violate your personal bubble again."
      "\n\nYou've now entered a hallway."
      "\nWalking along, you end up in front of two doors."
      "\n\nOn the left, the door seems to echo with the regrets of people that history has long since forgotten."
      "\nThe door on the right looks shy.";
    cout << "\nYou see someting lying on the ground between the two doors.";
    findItem(meme);
    cout << "\n\nDo you want to go through the left[l] or right[r] door?\n\n(enter l or r. Or something else. I don't care)\n-- ";
    cin >> door;
    while (door != 'r' && door != 'l')
    {
      cout << "The doors do not understand. The right door looks to be on the verge of tears. ";
      cout << "\nPlease try entering \'l' or \'r\' again. I don't know if the right door can handle it.";
      cin >> door;
    }
    if (door == 'l')
    {
      cout << "You go through the left door." << endl;
      fightEnemy(train);
      cout << "\nYou are immediately transported to a taco cart in space."
        "\nWh..What? The tacos look old too. The tamales don't look half bad."
        "\n\nBehind the cart is a man, playing with a deck of cards."
        "\nHe is wearing a name tag that says, \" Juan\""

        "\n\n\"Hola, Se" << spanishN << "or, I am the great magician, the Juan and only."
        "\n\"Would you like to see a magic trick?\""
        "\n\n(See magic trick? y/n) \n-- ";

      cin >> trick;

      while (trick != 'y' && trick != 'n')
      {
        cout << "\nRepite, por favor.\nWould you like to see a magic trick? (y/n)\n-- ";
        cin >> trick;
      }
      if (trick == 'y')
      {
        cout << "\n\"Great, it's a pretty good trick.\" says the magician.";
      }
      else if (trick == 'n')
      {
        cout << "\nToo late, looks like he's starting his trick.";
      }
      cout << "\n\n\"Okay, I'm going to disappear on the count of three.\" says Juan."
        "\nUno...\nDos...\n\nAnd he disappears without a tres.";
      switch (trick)
      {
      case 'y':
        cout << "Where the magician was, now there is just a note."
          "\n\nIt reads:"
          "\n\nTo proceed from here, all you need to do is"
          "\ntap the heels of you ratty Doc Martens together 3 times.";
        cout << "\n\nPretty straightforward. You do as the note says.";
        basement();
        break;
      case 'n':
        cout << "\n\nThe magician seemed upset that you did not want to see his trick."
          "\nLooks like the magician left you alone in space with his taco cart and no way of escaping."
          "\nFor hours, minutes even, you subsist on nothing but tacos."
          "\n\nEventually, however, you succumb to the intense solar radiation and perish.";
        playerDeath();
        playAg();
        break;
      }
    }
    else if (door == 'r')
    {
      cout << "\n\nYou step through the right door." << endl;
      fightEnemy(toupee);

      cout << "You enter the stock room of a grocery store. There are a ton of doors here, all of which lead to brick walls."
        "\n\nIn the middle of the room is a statue of the Grim Reaper feeding a blue and white plastic cow statue."
        "\nThe plaque under the statue reads, \"THE END OF ERICA\". Bizzarely morbid if you ask me."
        "\n\nYou walk up to the statue and behind it you find a trap door and a spiral staircase that seems to head up endlessly."
        "\nThe trap door tastes of Marzipan and your mother's meatloaf. The spiral staircase tastes like dust and butterscotch.";
      findItem(meme);
      cout << "\n\nDo you want to go up [u] or down[d]?\n\n-- ";
      cin >> trapStairs;
      while (trapStairs != 'u' && trapStairs != 'd')
      {
        cout << "\nMeatloaf or Butterscotch, dude it's not that hard.\n\n [u]p or [d]own\n-- ";
        cin >> trapStairs;
      }
      if (trapStairs == 'u')
      {
        cout << "\nYou decide to go up the stairs.";
        fightEnemy(giraffe);
        "\nYou walk up..."
          "\n\t...and up..."
          "\n\t\t...and up..."
          "\n\t\t\t...and up..."
          "\n\t\t\t\t...and up..."
          "\nAaaaaannnnnddd, now you're in...the basement?"
          "\n\n?????????????????????????????????????????????"
          "\n\nI don't get it either. Promise. Search me, I'm just a detatched voice.";
        cout << "\n\n[Press enter to continue]\n-- ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        basement();

      }
      else if (trapStairs == 'd')
      {
        cout << "\nYou decide to take the trap door."
          "\nOpening the trap door you find a fireman's pole. The top does not attatch to anything, but you still decide to slide down."
          "\n\nYou soon come to realize that the bottom of the pole is not connected to anything either."
          "\nIn retrospect, with everything that has happened today, that's not very suprising."
          "\n\nYou fall off the pole and land in a pit of Unicorn Horns.";
        playerDeath();
        cout << endl;
        playAg();

      }

    }
  }

  cout << "\n\nThank you for going on this adventure with me."
    "\nIt gets lonely in this console all by myself." << endl;
  cout << "\nCome back again sometime!" << endl;
  cout << "\n <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3" << endl;
  cin.get();
  cin.get();
  return 0;
}

void findItem(Item it)
{
  bool cont = true;

  char itemChoice;

  cout << "\n\nYou found " << it.getName() << "!" << endl;
  while (cont)
  {
    cout << "Would you like to [i]nspect it, [e]quip it, or [d]rop it?\n-- ";
    cin >> itemChoice;
    while (itemChoice != 'i' && itemChoice != 'e' && itemChoice != 'd')
    {
      cout << "\nI don't think you can do that with an item.";
      cout << "\nWould you like to[i]nspect it, [e]quip it, or [d]rop it ? \n-- ";
      cin >> itemChoice;
    }
    switch (itemChoice)
    {
    case 'i':
      cout << "You inspect " << it.getName() << endl;
      cout << it.getDesc() << endl;
      cout << "It adds " << it.getHP() << " HP." << endl;
      cout << "It adds " << it.getAttack() << " Attack." << endl;
      break;
    case 'e':
      cout << "You equip " << it.getName() << endl;
      equipItem(it);
      cont = false;
      break;
    case 'd':
      cout << "You drop " << it.getName() << endl;
      cont = false;
      break;
    }

  }
}

void equipItem(Item i)
{
  cout << "\n" << i.getName() << " equipped";
  userHP += i.getHP();
  userAttack += i.getAttack();

  cout << "\nUser HP: " << userHP << endl;
  cout << "User Attack: " << userAttack << endl;
}

void fightEnemy(Enemy e)
{
  char actionChoice;
  int damage;
  bool contFight = true;
  cout << "You encountered " << e.getName() << endl;
  while (contFight)
  {
    cout << "\nYou can try to [f]ight, [r]un, or [t]alk\n-- ";
    cin >> actionChoice;
    while (actionChoice != 'f' && actionChoice != 'r' && actionChoice != 't')
    {
      cout << "\nThe enemy is getting impatient. Is it really that hard to type a single letter?";
      cout << "\n[f]ight, [r]un, or [t]alk\n-- " << endl;
      cin >> actionChoice;
    }
    switch (actionChoice)
    {
    case 'f':
      cout << "\n You strike " << e.getName() << ". Dealt " << userAttack << " damage.";
      damage = e.getHP() - userAttack;
      e.setHP(damage);
      if (e.getHP() > 0)
      {
        cout << "\nThe enemy fights back. Dealt " << e.getAttack() << " damage.";
        userHP -= e.getAttack();
      }
      else
      {
        cout << "\nThe enemy dies.";
        contFight = false;
      }
      cout << "\nYour HP: " << userHP;
      cout << "\n" << e.getName() << "\'s HP: " << e.getHP();
      break;
    case 'r':
      if (e.getRun() == true)
      {
        cout << "You run from " << e.getName();
        contFight = false;
      }
      else
        cout << "\nYou can't run from this enemy.";
      break;
    case 't':
      cout << e.getTalk();
      break;

    }
  }
}

void printTitleScreen(void)
{
  cout <<
    "   _____                            __  __           _               _   __      __ "
    "\n  / ___/____  ____________  __      \\ \\/ /___  __  _( )________     / | / /___  / /_"
    "\n  \\__ \\/ __ \\/ ___/ ___/ / / /       \\  / __ \\/ / / /// ___/ _ \\   /  |/ / __ \\/ __/"
    "\n ___/ / /_/ / /  / /  / /_/ /        / / /_/ / /_/ / / /  /  __/  / /|  / /_/ / /_  "
    "\n/____/\\____/_/  /_/   \\__, ( )      /_/\\____/\\__,_/ /_/   \\___/  /_/ |_/\\____/\\__/  "
    "\n                     /____/|/                                                       ";

  cout <<
    "\n                       _ _ ______               _ _ "
    "\n   ____ ___  __  __   ( | )_  __/_  ______  ___( | )"
    "\n  / __ `__ \\/ / / /   |/|/ / / / / / / __ \\/ _ \\/|/ "
    "\n / / / / / / /_/ /        / / / /_/ / /_/ /  __/    "
    "\n/_/ /_/ /_/\\__, /        /_/  \\__, / .___/\\___/     "
    "\n          /____/             /____/_/               final version.";
}

void playerDeath(void)
{
  cout <<
    "\n _______        _____     _______   "
    "\n|_   __ \\      |_   _|   |_   __ \\  "
    "\n  | |__) |       | |       | |__) | "
    "\n  |  __ /        | |       |  ___/  "
    "\n _| |  \\ \\_  _  _| |_  _  _| |_  _  "
    "\n|____| |___|(_)|_____|(_)|_____|(_) " << endl;
  cout << "\n You have died." << endl;
}

void playAg(void)
{
  cout << "Would you like to play again? (y/n) \n-- ";
  cin >> playA;
  while (playA != 'y' && playA != 'n')
  {
    cout << "It's been a long day for both of us. I'd appreciate it if you just choose 'y' or 'n'\n-- ";
    cin >> playA;
  }
  switch (playA)
  {
  case 'y':
    playAgain = true;
    break;
  case 'n':
    playAgain = false;
    break;
  }

}

void basement(void)
{
  cout << "\n\nThe basement vaguely reminds you of your Uncle Phil\'s, a total blast from the past.";
  cout << "\n\nSeriously. the 70's called, they don't even want this crap back."
    "\n\nNope, you're on your own here buddy, you have to sift through all this junk on your own. ";
  cout << "\n\nWhile sifting through some of this junk you stumble upon something useful.";
  findItem(meme);
  cout << "\n\nFinally under a dozen boxes of  bell bottoms, some broken lava lamps, mood rings that predict danger,"
    "\nand other stuff that should never see the light of the future ever again,"
    "\nYou find what you're looking for.  A waterslide out of here!"
    "\nIt has a fork though. do you lean to the [l]eft or to the [r]ight?";
  cout << "\n-- ";
  cin >> lean;
  while (lean != 'l' && lean != 'r')
  {
    cout << "It's coming up. You'd better make up your mind. Like now. [l]eft or [right]\n-- ";
    cin >> lean;
  }
  if (lean == 'l')
  {
    cout << "\nThe waterslide starts to spin off towards the left."
      "\nThe tangential forces increase more and more."
      "\n\nYou're starting to get dizzy and your vision is fading."
      "\n\nYou black out like you're on a Bond villian's death trap."
      "\nEventually it spits you out looking like a half-drowned cat.";
    cout << "You wake up in a padded cell, wondering if you've belonged in one this entire time."
      "\nYou probably hallucinated everything that just happened."
      "\n\n I mean really,"
      "\nTarot cards?" << endl;
    cout << "\n\nYou find a towel on the floor of the cell";
    findItem(towel);
    cout << "\n\nThe cell seems to stretch out for miles."
      "\n\nOf Course.\n\nLuckily there's an electric longboard with your name on it.\n\nLiterally."
      "\n\nThe Pioneers used to ride these babies for miles!";
    cout << "\n\nYou get on the Longboard , but first";
    fightEnemy(puck);
    cout << "\n\nAt the end of the cell there's just a glass table with a bottle of maple syrup and a bag of gummy bears."
      "\nThe syrup has a tag that says \"Drink me\" and the gummy bears are tagged \"Eat me\"."
      "\nWho the heck wants to drink maple syrup?";
    cout << "\n\nYou go to eat the gummy bears but on closer inspection they're sugar free."
      "\nWhatever you do, I have to do too and you are NOT about to put us through that. Nuh-uh."
      "\nMaple syrup it is."
      "\n\n Ugh, it was minty!";
    findItem(mug);
    cout << "\n\n You get dizzy. You are bareley able to make out a shape coming towards you." << endl;
    fightEnemy(teeth);
    cout << "\n\nThe walls crumble away and reveal an ancient tomb,"
      "\nguarded by " << beast << ".";
    cout << "\n\n" << beast << " says,"
      "\n\"If you have the right key, then I will take you back to your home.\" They say with an air of mysteriousness.";
    cout << "\n\nA key? all you have are:\n\n ";
    cout << "Tarot Cards:";
    for (int i = 0; i < 3; i++)
    {
      cout << cards[i].getName() << endl;
    }

    cout << "[Press enter to continue]\n-- ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin.get();
    cout << "\n\nOH! Wait a sec. "
      "\n\n That last tarot card! We have no idea what it does, and it's not like anything else makes sense in this world."
      "\nwhat if it's the key " << beast << " is lookingfor?.";
    if (cards[2].getName() == "The Void")
    {
      cout << "\n\n" << beast << " looks your card over, and spears it with his swordfish head."
        "\n\nThey accept your card and a flight attendant welcomes you aboard " << beast;
      cout << "\n\nPRAISE\nSWEET\nHEAVEN.";
      cout << "\n\nOnce aboard the plane, the flight attendant knocks you out with a pineapple"
        "\nand you find yourself jerking awake. ";
      cout << "\n\nIt was a dream! You're finally out of that random, concerning purgatory!";
      cout << "\n\nMaybe next time you'll know to not fall asleep in CS 1400.";
      playAg();
    }
    else
    {
      cout << "\n\n" << beast << " looks your card over and laughs a terrifying laugh from deep within"
        "\ntheir Boeing 747 cabin! He does NOT accept your card!"
        "\n\nYou try to run in vain. THey catch you and thesturgeon head swallows you whole.";
      playerDeath();
      playAg();
    }

    /*
    cout << "\n\nHow do you respond? :";
    getline(cin, answer);
    string answerLower;
    for (int i = 0; i < answer.length(); ++i)
    {
    answerLower += answer[i];
    }
    bool rightAns = false;
    cout << "\nYou have answered ";
    for (int i = 0; i < answerLower.length() - sphynx[riddleNum].getAnswer().length(); ++i)
    {
    if (sphynx[riddleNum].getAnswer() == answerLower.substr(i, sphynx[riddleNum].getAnswer().length()))
    {
    cout << "CORRECTLY." << endl;
    rightAns = true;
    break;
    }
    }
    if (!rightAns)
    {
    cout << "INCORRECTLY." << endl;
    }
    if (sphynx[riddleNum].getAnswer() == "death")
    {
    playerDeath();
    playAg();
    }
    else if (sphynx[riddleNum].getAnswer() == "puck")
    fightEnemy(puck);
    else
    cout << "\nYou are permitted to continue on your way.";
    }
    //playAg();
    */
  }

  else if (lean == 'r')
  {
    cout << "\nThe right path slows down a bit."
      "\nAhead, the waterslide appears to drop off sharply.";
    cout << "\n\nUh oh."
      "\n\"I'm about to go off a huge waterfall, aren't I?\" you say."
      "\nYep."
      "\n\"Sharp rocks at the bottom?"
      "\nProbably."
      "\n\"Bring it on\"";
    playerDeath();
    playAg();
  }
}

/*
bool ridAnswer(riddle r, string a)
{
if (r.getAnswer() == "death")
{
return false;
}
string s;
for (int i = 0; i < r.getAnswer().length; ++i)
{
s+=tolower(r.getAnswer()[i]);
}
string t;
for (int i = 0; i < a.length; ++i)
{
t += tolower(a[i]);
}
for (int i = 0; i < a.length(); ++i)
{
if (r.getAnswer() == a.substr(i, r.getAnswer().length()))
return true;
}
return false;
}
*/