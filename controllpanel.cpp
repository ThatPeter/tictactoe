#include "controllpanel.h"

using namespace std;

void infoPanel()
{
    cout << "TIC TAC TOE GAME MADE BY - ME" << endl << endl;
    cout << "HOW TO PLAY:" << endl << endl;
    cout << "1. CHOOSE FORMAT (BEST OF X GAMES, X HAS TO BE A WHOLE NUMBER LARGER THAN 0)" << endl << endl;
    cout << "2. PICK THE POSITION WHERE YOU WANT TO PLACE YOUR TIC OR TAC" << endl;
    cout << "   HOW TO PICK A POSITION: TYPE THE ROW AND COLUMN YOU WANT TO" << endl;
    cout << "   PLACE THE TIC/TAC IN THE FOLLOWING FORMAT: ROW(NOSPACE)COLUMN" << endl;
    cout << "   EXAMPLE: 11 - PLACES IN THE FIRST ROW OF THE FIRST COLUMN" << endl;
    cout << "   WARNING: THE FIELD HAS ONLY 3 ROWS AND 3 COLUMNS" << endl << endl;
    cout << "3. TRY TO LINE UP 3 OF YOUR SYMBOLS DIAGONALLY,HORIZONTALLY OR VERTICALLY" << endl << endl;
    cout << "4. WIN THE MAJORITY OF THE GAMES AND BECOME THE ULTIMATE TIC TAC TOE CHAMPION" << endl;
    cout << endl << endl;
}

int setPosition(string what)
{
    unsigned int position;

    cout << what;
    cin >> position;
    cout << endl << endl;

    return position;
}

string setName()
{
    string playerName;

    cout << endl << endl;
    cout << "Enter your desired name: ";
    cin >> playerName;
    cout << endl << endl;

    return playerName;
}

int setFormat()
{
    string bestOfStr;
    int bestOfX;
    /*cycle continues until correct format is entered(a whole positive number)*/
    do
    {
        try 
        {
            cout << "Choose format: ";
            cin >> bestOfStr;
            bestOfX = stoi(bestOfStr);
            cout << bestOfX << " " << bestOfStr;
        }
        catch (exception e)
        {
            cerr << "Incorrect format, try again" << endl << endl;
            setFormat();
        }

    } while (bestOfX < 1);

    return bestOfX;
}