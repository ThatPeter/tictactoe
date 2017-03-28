#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <map>
#include "sides.h"

using namespace std;

class Playfield
{
private:
    map<int, char> m_field;

protected:
    const int	  m_fieldSize = 3;
    unsigned int  m_nOfMoves;

public:
    Playfield();
       
    ~Playfield();
    
    map<int, char> getPlayField();
   

    char sidesToOutputChar(Sides side);
    

    void resetPlayfield();
    

    void setFieldValue(int position, Sides side);
   
    
    void printField();

};
#endif  

