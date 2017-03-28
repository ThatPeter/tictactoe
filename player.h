#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "sides.h"

using namespace std;

struct Player
{
    int		points;
    string	name;
    Sides	side;
};

#endif // ! PLAYER_H
