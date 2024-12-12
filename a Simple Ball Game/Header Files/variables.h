#pragma once


#define KEY_LEFT 75   // these are arrow keys defenation; starting with left key.
#define KEY_RIGHT 77  // right key.
#define KEY_UP 72     // up key.
#define KEY_DOWN 80   // down key.
#define KEY_ENTER 10  // enter key.

enum DIR // this eNUMs is for directions of the ball.
{
    STOP = 0,
    DOWNLEFT = 1,
    DOWNRIGHT = 2,
    DOWN = 3
};