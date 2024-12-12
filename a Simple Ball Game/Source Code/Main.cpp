#include "../Header Files/Libraries.h"
#include "../Header Files/variables.h"
#include "../Classes/BallClass.h"
#include "../Classes/Panel.h"
#include "../Classes/Game_Runner.h"

void gotoxy(int, int); // this function takes screen pointer to x, y Cordinates.

int main()
{
    SetConsoleOutputCP(6001);   // set fonts to UniCode.
    system("Color 0B");         // set color to Black - light Blue.
    bool me1, me2, ini = false; // variables for the menu.
    me1 = me2 = false;
    while (true) // making a while to showing the menu.
    {
        if (!(me1 == false && me2 == false)) // if menu shows for the first time.
        {

            char keyNow = _getch();
            if (keyNow == ' ')
            {
                if (me1 == true && me2 == false)
                {
                    goto starter;
                }
                else if (me2 == true && me1 == false)
                {
                    system("cls");
                    return 0;
                }
            }
        }
        if (!ini) // this is for showing menu.
        {
            gotoxy(15, 4);
            std::cout << "New Game";
            gotoxy(15, 5);
            std::cout << "Quit Game\n";
            gotoxy(13, 4);
            std::cout << "\u25BA";
            if (_getch() == ' ')
                goto starter;
        }
        switch (_getch())
        {
        case KEY_UP:
            ini = true;
            me1 = true;
            me2 = false;
            system("cls");
            gotoxy(15, 4);
            std::cout << "New Game";
            gotoxy(15, 5);
            std::cout << "Quit Game\n";
            gotoxy(13, 4);
            std::cout << "\u25BA";
            break;
        case KEY_DOWN:
            ini = true;
            me2 = true;
            me1 = false;
            system("cls");
            gotoxy(15, 4);
            std::cout << "New Game";
            gotoxy(15, 5);
            std::cout << "Quit Game\n";
            gotoxy(13, 5);
            std::cout << "\u25BA";
            break;
        }
    }
starter:
    GameRunner RunNewGame;   // we create an object for running the game.
    RunNewGame.RunTheGame(); // now we run it.
    std::cout << std::endl;
    return 0;
}