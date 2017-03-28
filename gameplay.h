#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stack>
#include "playfield.h"
#include "player.h"

using namespace std;

class Gameplay : protected Playfield
{
private:
    stack<Sides> m_moves;
    unsigned int m_bestOfX;

    Player *m_human =   new Player;
    Player *m_AI =      new Player;

public:
    Gameplay(int bestOfX, string playerName);
        

    ~Gameplay();


    Player *playerAI();
  

    Player *playerHuman();
   

    Player *getPlayer(Sides side);
  

    Sides accessSide(Player *player);
   

    void setSides(Sides side);
  

    void switchSides();
  

    string playerNameBySide(Sides side);
    

    string humanName();
   

    string aiName();
   

    void clearMoves();
    

    Sides getMove();
   

    void moveMade();
 

    bool noMoreMoves();
    

    void fillMoves();
    

    void resetMoves();
   

    int accessPoints(Player *player);
  

    void pointMade(Sides side);
   

    int magic(string str, int i, int j);
    

    bool checkDiagonals(map<int, char> field, char reference, string what);
    

    bool checkRowsAndColumns(map<int, char> field, char reference, string what);
    

    bool winnerFound(map<int, char> field, Sides side);


    void setWhoStarts();


    void gameWinner(Sides current, int gameNumber);


    void seriesWinner();
};

#endif // ! GAMEPLYAY_H

