#include "playfield.h"
#include "controllpanel.h"

    Playfield::Playfield()
    {
        resetPlayfield();
    };

    Playfield::~Playfield()
    {

    }

    map<int, char> Playfield::getPlayField()
    {
        return m_field;
    }

    char Playfield::sidesToOutputChar(Sides side)
    {
        switch (side)
        {
        case CROSS:	    return 'X';

        case CIRCLE:    return 'O';

        default:	    return 0;

        }
    }

    void Playfield::resetPlayfield()
    {
        m_field =
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
        m_nOfMoves = 0;
    }

    void Playfield::setFieldValue(int position, Sides side)
    {
        try
        {
            if (m_field.at(position) == 'X' || m_field.at(position) == 'O')
            {
                position = setPosition("Position already taken, try again\nNew position : ");
                setFieldValue(position, side);
            }
            else
            {
                m_field.at(position) = sidesToOutputChar(side);
                m_nOfMoves++;
            }
        }

        catch (out_of_range e)
        {
            cerr << e.what() << endl << endl;

            position = setPosition("You entered an incorrect position, try again\nNew position : ");
            setFieldValue(position, side);
        }
    }

    /*------------ A MESSY PRINTING FUNCTION ------------*/
    void Playfield::printField()
    {
        cout << "-------------------" << endl;
        cout << "   Move number " << m_nOfMoves << endl << endl;
        cout << endl << "     1  2  3" << endl << endl;

        int enterCounter = 0;
        int i = 1;

        for (auto const &it : m_field)
        {
            if (enterCounter % 3 == 0)
                cout << "  " << i++ << "  ";

            if (it.second != 'X' && it.second != 'O')
                cout << "-" << "  ";
            else
                cout << (it.second) << "  ";

            if ((enterCounter++ + 1) % 3 == 0)
                cout << endl << endl;
        } 
 
        cout << "-------------------" << endl;
        cout << endl << endl;
    }

