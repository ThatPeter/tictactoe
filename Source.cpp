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
    
	return EXIT_SUCCESS;
}
