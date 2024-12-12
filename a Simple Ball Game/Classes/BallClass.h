#pragma once

#include "../Header Files/Libraries.h"
#include "../Header Files/variables.h"

class MainBall
{
private:
    int x_Axis;         // this is the x Axis of the Ball.
    int y_Axis;         // this is the y Axis of the Ball.
    int OriginalX_Axis; // we use this x later to reset the ball position.
    int OriginalY_Axis; // and start the game over.
    DIR direction;      // direction of the ball.

public:
    MainBall(int xPOS, int yPOS = 1) // constructor for the Ball.
    {
        OriginalX_Axis = xPOS;
        OriginalY_Axis = yPOS;
        x_Axis = xPOS;
        y_Axis = yPOS;
        direction = BallrandomDirection();
    }
    void resetBall() // this function will rest the ball.
    {
        x_Axis = OriginalX_Axis;
        y_Axis = OriginalY_Axis;
        direction = BallrandomDirection();
    }
    void changeDirections(DIR CurrentDirection) // this function changes the direction of the ball.
    {
        direction = CurrentDirection;
    }
    inline int getX() // this function gets X Axis of the ball. it is inline so compiler doesn't call it.
    {
        return x_Axis;
    }
    inline int getY() // this function gets Y Axis of the ball. it is inline so compiler doesn't call it.
    {
        return y_Axis;
    }
    inline DIR getDirection() // this function gets direction of the ball. it is inline so compiler doesn't call it.
    {
        return direction;
    }
    DIR BallrandomDirection() // this function generates a random direction for the ball.
    {
        srand((unsigned int)time(NULL));
        return (DIR)((rand() % 3) + 1);
    }
    void moveTheBall() // this function causes the move of the ball.
    {
        switch (direction) // this switch determines X and Y Axis values.
        {
        case STOP:
            break;
        case DOWNLEFT:
            x_Axis++;
            y_Axis++;
            break;
        case DOWNRIGHT:
            x_Axis--;
            y_Axis++;
            break;
        case DOWN:
            y_Axis++;
            break;
        default:
            break;
        }
    }
};



