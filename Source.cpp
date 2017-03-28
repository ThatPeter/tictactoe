#include <iostream>
#include <stack>
#include <map>
#include <string>
#include "controllpanel.h"
#include "gameplay.h"
#include "playfield.h"
#include "sides.h"
#include "ai.h"

using namespace std;

int main()
{
    /*
    map<int, char> field;
    field =
    {
        { 11, 0 },
        { 12, 0 },
        { 13, 0 },
        { 21, 0 },
        { 22, 0 },
        { 23, 0 },
        { 31, 0 },
        { 32, 0 },
        { 33, 0 }
    };

    bestMoveTEST(field,CROSS,10);
    */

	infoPanel();

    int position;
	string playerName =     setName();
    unsigned int bestOfX =  setFormat();

	Playfield playfield;
	Gameplay gameplay(bestOfX, playerName);

	gameplay.setWhoStarts();

	

	for (int i = 1; i <= bestOfX; i++) {

		cout << "---GAME NUMBER " << i << "---" << endl << endl;

		playfield.printField();

		while (!gameplay.noMoreMoves())
		{	
            position = setPosition("Type in the position you want to place your symbol: ");
	
			Sides current = gameplay.getMove();
	
			playfield.setFieldValue(position, current);
			playfield.printField();

			if (gameplay.winnerFound(playfield.getPlayField(), current))
			{   
				gameplay.gameWinner(current, i);
				break;
			}
			gameplay.moveMade();
		}

		if(gameplay.noMoreMoves())
			cout << "This battle ended in a draw" << endl << endl;

		gameplay.clearMoves();
		gameplay.resetMoves();
		gameplay.switchSides();
		playfield.resetPlayfield();
	}
    
	gameplay.seriesWinner();
    
	system("pause");
	return EXIT_SUCCESS;
}