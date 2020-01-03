#include <ncurses.h>

#include "headers/output.h"
#include "headers/draw.h"

int main(int argc, char **argv)
{
    int row,
        column,
        key,
        row_option_indicator = 1;

    char
        *option_1 = "Restart system",
        *option_2 = "Poweroff",
        *option_3 = "option3",
        *indicator = ">";

    initscr();

    noecho();
    curs_set(0);
    keypad( stdscr, TRUE );
    getmaxyx(stdscr, row, column);
    attron(A_BOLD);

    border_term();
    mvprintw( (row / 2) - 1, ( column / 2 ) - ( sizeof( option_1 ) / 2 ), option_1 );
    mvprintw( row / 2,( column / 2 ) - ( sizeof( option_2 ) / 2 ), option_2 );
    mvprintw( (row / 2) + 1, ( column / 2 ) - ( sizeof( option_3 ) / 2 ), option_3 );


    do
    {
        key = getch();

        if (key == KEY_UP)
        {
            test_output();
        }
        else if (key == 'q')
        {
            break;
        }
    } while (key);

    endwin();
    return 0;
}