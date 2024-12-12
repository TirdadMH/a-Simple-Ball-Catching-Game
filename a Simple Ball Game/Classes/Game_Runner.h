#pragma once

#include "../Header Files/Libraries.h"
#include "../Header Files/variables.h"
#include "../Classes/BallClass.h"
#include "../Classes/Panel.h"

void gotoxy(int, int); // this function takes screen pointer to x, y Cordinates.

class GameRunner // this class runs and manages the game.
{
private:
    int lives;
    int randomBall; // showing random ball as second ball.
    std::string baaaal;
    int Score = 0; // score for the player.
    int PanelLeft, PanelRight;
    bool QuitGame, show_second_ball = false; // boolian variable to quit game.
    Panel* Pointer_to_panel;                 // our panel.
    MainBall* pointer_to_ball;               // the ball.
    MainBall* pointer_to_ball2;              // ball 2

public:
    GameRunner() // GameRunner constructor for this class, witch will be used to run the game for the first time.
    {
        srand((unsigned int)time(NULL));
        randomBall = (rand() % 4) + 1;
        switch (randomBall)
        {
        case 1:
            baaaal = "🏀";
            break;
        case 2:
            baaaal = "⚾";
            break;
        case 3:
            baaaal = "🏐";
            break;
        case 4:
            baaaal = "🥎";
            break;
        }
        lives = 3; // players lives.
        srand((unsigned int)time(NULL));
        QuitGame = false;
        // PanelLeft = KEY_LEFT, PanelRight = KEY_RIGHT; // use to control panel with Arrow Keys.
        PanelLeft = 'a', PanelRight = 'd'; // use to control panel with A & D Keys.
        srand((unsigned int)time(NULL));
        pointer_to_ball = new MainBall((rand() % 20 + 1));
        srand((unsigned int)time(NULL));
        pointer_to_ball2 = new MainBall((rand() % 16 + 18));
        Pointer_to_panel = new Panel(19, 28);
    }
    ~GameRunner() // destructor for the GameRunner.
    {
        delete pointer_to_ball, Pointer_to_panel;
    }

    void GameDraw() // this function draws the game.
    {
        system("CLS");
        if (pointer_to_ball->getY() == 11)
        {
            pointer_to_ball2->resetBall();
            show_second_ball = true;
        }

        if (show_second_ball)
        {
            gotoxy(pointer_to_ball2->getX(), pointer_to_ball2->getY()); // draws the ball.
            std::cout << baaaal;
            gotoxy(0, 0);
        }
        gotoxy(pointer_to_ball->getX(), pointer_to_ball->getY()); // draws the ball.
        std::cout << "⚽";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) - 4), Pointer_to_panel->getPY()); // from here to line : 200 we draw the panel.
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) - 3), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) - 2), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) - 1), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(Pointer_to_panel->getPX(), Pointer_to_panel->getPY());
        std::cout << "\u2566";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) + 1), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) + 2), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) + 3), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        gotoxy(((Pointer_to_panel->getPX()) + 4), Pointer_to_panel->getPY());
        std::cout << "\u2550";
        gotoxy(0, 0);
        int j = 0;
        for (int i = 0; i < 40; i++) // draws the walls from here to line : 225.
        {
            std::cout << "\u2588";
        }
        j++;
        for (int k = 0; k < 28; k++)
        {
            for (int i = 0; i < 40; i++)
            {
                if (i == 0 | i == 39)
                {
                    gotoxy(i, j);
                    std::cout << "\u2588";
                }
            }
            j++;
        }
        std::cout << std::endl;
        for (int i = 0; i < 40; i++)
        {
            std::cout << "\u2588";
        }
        std::cout << std::endl
            << std::endl;
        gotoxy(50, 60); // shows the score.
        std::cout << "Score : " << Score << '\t' << "Lives Left : " << lives;
        gotoxy(0, 0);
    }

    void BallRefresh() // this function moves the ball.
    {
        pointer_to_ball->moveTheBall();
        pointer_to_ball2->moveTheBall();
        Sleep(75);
        fflush(stdin);
    }

    void KeyInput() // this function defines panel input and it's logic.
    {
        if (_kbhit())
        {
            char currentMove = _getch();
            if (currentMove == 'A' || currentMove == 'D') // to use with CapsLock on.
            {
                currentMove = tolower(currentMove);
            }
            if (currentMove == PanelRight) // right  wall limit.
            {
                if (Pointer_to_panel->getPX() == 34)
                    goto label2;
                else
                    Pointer_to_panel->PanelMoveRight();
            }
        label2:
            if (currentMove == PanelLeft)
            {
                if (Pointer_to_panel->getPX() == 4) // left wall limit.
                    goto label3;
                else
                    Pointer_to_panel->PanelMoveLeft();
            }
        label3:
            if (currentMove == 'q') // q for quit game.
                QuitGame = true;
            system("cls");
        }
    }

    void GameLogic() // this function manages the game logic.
    {
        int SXB = pointer_to_ball->getX();
        int SYB = pointer_to_ball->getY();
        int SXB2 = pointer_to_ball2->getX();
        int SYB2 = pointer_to_ball2->getY();
        int SXP = Pointer_to_panel->getPX();
        int SYP = Pointer_to_panel->getPY();
        if (SXB == 1)
        {
            if (pointer_to_ball->getDirection() == DOWNLEFT) // logic for ball when hits the walls. this is for the left wall.
                pointer_to_ball->changeDirections(DOWNRIGHT);
            else if (pointer_to_ball->getDirection() == DOWNRIGHT)
                pointer_to_ball->changeDirections(DOWNLEFT);
        }
        else if (SXB == 37)
        {
            if (pointer_to_ball->getDirection() == DOWNLEFT) // logic for ball when hits the walls. this is for the right wall.
                pointer_to_ball->changeDirections(DOWNRIGHT);
            else if (pointer_to_ball->getDirection() == DOWNRIGHT)
                pointer_to_ball->changeDirections(DOWNLEFT);
        }
        if (SXB2 == 1)
        {
            if (pointer_to_ball2->getDirection() == DOWNLEFT) // logic for the second ball when hits the left walls.
                pointer_to_ball2->changeDirections(DOWNRIGHT);
            else if (pointer_to_ball2->getDirection() == DOWNRIGHT)
                pointer_to_ball2->changeDirections(DOWNLEFT);
        }
        else if (SXB2 == 37)
        {
            if (pointer_to_ball2->getDirection() == DOWNLEFT) // logic for the second ball when hits the right walls.
                pointer_to_ball2->changeDirections(DOWNRIGHT);
            else if (pointer_to_ball2->getDirection() == DOWNRIGHT)
                pointer_to_ball2->changeDirections(DOWNLEFT);
        }
        // blow is the logic for the winning the game.
        if (SYB == SYP && ((SXB - 4) == SXP || (SXB - 3) == SXP || (SXB - 2) == SXP || (SXB - 1) == SXP || (SXB) == SXP || (SXB + 1) == SXP || (SXB + 2) == SXP || (SXB + 3) == SXP || (SXB + 4) == SXP))
        {
            Score++;
            pointer_to_ball->resetBall();
        }
        if (SYB2 == SYP && ((SXB2 - 4) == SXP || (SXB2 - 3) == SXP || (SXB2 - 2) == SXP || (SXB2 - 1) == SXP || (SXB2) == SXP || (SXB2 + 1) == SXP || (SXB2 + 2) == SXP || (SXB2 + 3) == SXP || (SXB2 + 4) == SXP))
        {
            Score++;
            srand((unsigned int)time(NULL));
            randomBall = (rand() % 4) + 1;
            switch (randomBall)
            {
            case 1:
                baaaal = "🏀";
                break;
            case 2:
                baaaal = "⚾";
                break;
            case 3:
                baaaal = "🏐";
                break;
            case 4:
                baaaal = "🥎";
                break;
            }
            pointer_to_ball2->resetBall();
        }
        // blow is the logic for the losing the game.
        else if (SYB == SYP && !((SXB - 4) == SXP || (SXB - 3) == SXP || (SXB - 2) == SXP || (SXB - 1) == SXP || (SXB) == SXP || (SXB + 1) == SXP || (SXB + 2) == SXP || (SXB + 3) == SXP || (SXB + 4) == SXP))
        {
            if (lives == 0)
            {
                lives = 4;
                Score = 0;
                system("cls");
                std::cout << "you lost! do you like to play another game?\n"; // asking user if they want to run another game.
                std::cout << "Y for Yes, N for No.\n";
            label1:
                switch (_getch())
                {
                case 'Y':
                case 'y':
                    Pointer_to_panel->ResetPanel();
                    pointer_to_ball->resetBall();
                    break;
                case 'N':
                case 'n':
                    exit(0);
                    break;
                default:
                    goto label1;
                    break;
                }
            }
            lives--;
            pointer_to_ball->resetBall();
        }
        else if (SYB2 == SYP && !((SXB2 - 4) == SXP || (SXB2 - 3) == SXP || (SXB2 - 2) == SXP || (SXB2 - 1) == SXP || (SXB2) == SXP || (SXB2 + 1) == SXP || (SXB2 + 2) == SXP || (SXB2 + 3) == SXP || (SXB2 + 4) == SXP))
        {
            if (lives == 0)
            {

                lives = 4;
                Score = 0;
                system("cls");
                std::cout << "you lost! do you like to play another game?\n"; // asking user if they want to run another game.
                std::cout << "Y for Yes, N for No.\n";
            label12:
                switch (_getch())
                {
                case 'Y':
                case 'y':
                    Pointer_to_panel->ResetPanel();
                    pointer_to_ball2->resetBall();
                    break;
                case 'N':
                case 'n':
                    exit(0);
                    break;
                default:
                    goto label12;
                    break;
                }
            }
            srand((unsigned int)time(NULL));
            randomBall = (rand() % 4) + 1;
            switch (randomBall)
            {
            case 1:
                baaaal = "🏀";
                break;
            case 2:
                baaaal = "⚾";
                break;
            case 3:
                baaaal = "🏐";
                break;
            case 4:
                baaaal = "🥎";
                break;
            }
            lives--;
            pointer_to_ball2->resetBall();
        }
    }

    void RunTheGame() // this function actually runs the game in a loop that QuitGame isn't true.
    {
        // int page = 0;
        while (!QuitGame)
        {
            // _setactivepage (page);
            // _setvisualpage (1-page);
            GameDraw();    // first we draw.
            BallRefresh(); // then we move the ball.
            KeyInput();    // we get key input.
            GameLogic();   // we run the logic.
            // page = 1 - page;
        }
    }
};