#include "../Header Files/Libraries.h"

void gotoxy(int x, int y) // this function takes screen pointer to desired x, y.
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}