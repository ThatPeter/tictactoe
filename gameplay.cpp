#include "gameplay.h"
#include <iostream>

    Gameplay::Gameplay(int bestOfX, string playerName)
        : m_bestOfX(bestOfX)
    {
        m_AI->points =      0;
        m_human->points =   0;
        m_AI->name =        "AI";
        m_human->name =     playerName;
        fillMoves();
    }

    Gameplay::~Gameplay()
    {
        //	delete m_human;
        //	delete m_AI;
    }

    Player *Gameplay::playerAI()
    {
        return m_AI;
    }

    Player *Gameplay::playerHuman()
    {
        return m_human;
    }

    Player *Gameplay::getPlayer(Sides side)
    {
        if (m_human->side == side)
            return playerHuman();
        else
            return playerAI();
    }

    Sides Gameplay::accessSide(Player *player)
    {
        return player->side;
    }

    void Gameplay::setSides(Sides side)
    {
        m_human->side = side;
        m_AI->side = m_human->side == CROSS ? CIRCLE : CROSS;
    }

    void Gameplay::switchSides()
    {
        if (m_human->side == CROSS)
        {
            setSides(CIRCLE);
        }
        else
        {
            setSides(CROSS);
        }
    }

    string Gameplay::playerNameBySide(Sides side)
    {
        Player *player = getPlayer(side);
        return player->name;
    }

    string Gameplay::humanName()
    {
        return m_human->name;
    }

    string Gameplay::aiName()
    {
        return m_AI->name;
    }

    void Gameplay::clearMoves()
    {
        while (!m_moves.empty())
            m_moves.pop();
    }

    Sides Gameplay::getMove()
    {
        return m_moves.top();
    }

    void Gameplay::moveMade()
    {
        m_moves.pop();
    }

    bool Gameplay::noMoreMoves()
    {
        return m_moves.empty();
    }

    void Gameplay::fillMoves()
    {
        for (int i = 0; i < 9; i++)
            i % 2 == 0 ? m_moves.push(CROSS) : m_moves.push(CIRCLE);
    }

    void Gameplay::resetMoves()
    {
        fillMoves();
    }

    int Gameplay::accessPoints(Player *player)
    {
        return player->points;
    }

    void Gameplay::pointMade(Sides side)
    {
        Player *player = getPlayer(side);
        player->points++;
    }
    // dont even ask
    int Gameplay::magic(string str, int i, int j)
    {
        if (str == "row")
            return i * 10 + j;

        else if (str == "column")
            return j * 10 + i;

        else if (str == "d1")
            return i * 11;

        else if (str == "d2")
            return i * 10 + (4 - i);
    }

    bool Gameplay::checkDiagonals(map<int, char> field, char reference, string what)
    {
        bool diagonalMatches = true;

        for (int i = 1; i <= m_fieldSize; i++)
        {
            if (field[magic(what, i, 0)] != reference)
                diagonalMatches = false;
        }
        if (diagonalMatches == true)
            return true;

        return false;
    }

    bool Gameplay::checkRowsAndColumns(map<int, char> field, char reference, string what)
    {
        bool columnMatches;
        for (int i = 1; i <= m_fieldSize; i++)
        {
            columnMatches = true;
            for (int j = 1; j <= m_fieldSize; j++)
            {
                if (field[magic(what, i, j)] != reference)
                    columnMatches = false;
            }
            if (columnMatches == true)
                return true;
        }
        return false;
    }

    bool Gameplay::winnerFound(map<int, char> field, Sides side)
    {
        char reference = sidesToOutputChar(side);
        bool foundAWinner = false;
        foundAWinner |= checkDiagonals(field, reference, "d1");
        foundAWinner |= checkDiagonals(field, reference, "d2");
        foundAWinner |= checkRowsAndColumns(field, reference, "row");
        foundAWinner |= checkRowsAndColumns(field, reference, "column");
        return foundAWinner;
    }

    void Gameplay::setWhoStarts()
    {
        cout << "Choose your side by typing who starts (\"me\" or \"ai\"): ";
        cout << endl << endl;

        string theStartingOne;

        do {
            cin >> theStartingOne;
            if (theStartingOne == "me")
            {
                setSides(CROSS);
                break;
            }
            else if (theStartingOne == "ai")
            {
                setSides(CIRCLE);
                break;
            }
            else
                cout << "Try again" << endl << endl;
        } while (theStartingOne != "me" || theStartingOne != "ai");
    }


    void Gameplay::gameWinner(Sides current, int gameNumber)
    {
        pointMade(current);
        cout << playerNameBySide(current) << " wins ";
        cout << "game number " << gameNumber << endl << endl;
    }

    void Gameplay::seriesWinner()
    {
        int humanPoints =   accessPoints(playerHuman());
        int aiPoints =      accessPoints(playerAI());
        string human =      humanName();
        string AI =         aiName();

        if (humanPoints > aiPoints)
        {
            cout << human << " wins the series ";
            cout << humanPoints << " to " << aiPoints << endl << endl;
        }
        else if (humanPoints < aiPoints)
        {
            cout << AI << " wins the series ";
            cout << aiPoints << " to " << humanPoints << endl << endl;
        }
        else
        {
            cout << "The series ended in a draw! ";
            cout << humanPoints << " to " << aiPoints << endl << endl;
        }
    }