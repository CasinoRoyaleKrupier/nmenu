#include <stdlib.h>
#include <ncurses.h>

#include "headers/draw.h"

int main(int argc, char **argv)
{
    int row,
        column,
        key,
        y_option_indicator[] = {3, 4, 5, 6},
        x_option_indicator = 4,
        actual_option = 1;

    char
        *option[] = {
            "Restart system",
            "Poweroff",
            "Open in github repository",
            "Exit",
        },
        indicator[] = ">";

    initscr();

    noecho();
    curs_set(0);
    keypad( stdscr, TRUE );
    getmaxyx(stdscr, row, column);
    attron(A_BOLD);

    border_term();
    mvprintw( 3, 6, option[0] );
    mvprintw( 4, 6, option[1] );
    mvprintw( 5, 6, option[2] );
    mvprintw( 6, 6, option[3] );

    mvprintw(3, 4, "%c", indicator[0]);

    int i = 0;
    do
    {
        key = getch();

        if (key == KEY_UP)
        {
            mvprintw(y_option_indicator[i], x_option_indicator, " ");
            mvprintw(y_option_indicator[--i], x_option_indicator, "%c", indicator[0]);
            actual_option--;

            if (actual_option <= 0)
            {
                actual_option++;
                mvprintw(y_option_indicator[i], x_option_indicator, " ");
                mvprintw(y_option_indicator[++i], x_option_indicator, "%c", indicator[0]);
            }

        }
        else if (key == KEY_DOWN)
        {
            mvprintw(y_option_indicator[i], x_option_indicator, " ");
            mvprintw(y_option_indicator[++i], x_option_indicator, "%c", indicator[0]);
            actual_option++;

            if (actual_option >= 5)
            {
                actual_option--;
                mvprintw(y_option_indicator[i], x_option_indicator, " ");
                mvprintw(y_option_indicator[--i], x_option_indicator, "%c", indicator[0]);
            }
        }
        else if (key == KEY_ENTER || key == '\n')
        {
            if (actual_option == 1)
            {
                system("reboot");
            }
            else if (actual_option == 2)
            {
                system("poweroff");
            }
            else if (actual_option == 3)
            {
                system("set echo off && firefox https://github.com/CasinoRoyaleKrupier/nmenu");
            }
            else if (actual_option == 4)
            {
                break;
            }
        }

        else if (key == 'q')
        {
            break;
        }
    } while (key);

    endwin();
    return 0;
}