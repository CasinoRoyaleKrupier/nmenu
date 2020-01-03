#include "headers/draw.h"

void border_term(void)
{
    int row,
        column;

    char border_char[] = "+";

    getmaxyx(stdscr, row, column);

    for (size_t i = 0; i < column; i++)
    {
        mvprintw(0, i, "%c", border_char[0]);
        mvprintw(row - 1, i, "%c", border_char[0]);
    }

    for (size_t i = 0; i < row; i++)
    {
        mvprintw(i, 0, "%c", border_char[0]);
        mvprintw(i, column - 1, "%c", border_char[0]);
    }
}