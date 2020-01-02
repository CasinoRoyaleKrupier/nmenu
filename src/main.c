#include <ncurses.h>

int main(int argc, char **argv)
{
    int row,
        column,
        key;

    char *text = "Hello world";

    initscr();

    getmaxyx(stdscr, row, column);

    mvprintw(row / 2, (column / 2) - (sizeof(text) / 2), text);
    move(0, 0);

    do
    {
        key = getch();
        move(row++, column++);
    } while (key != 27);

    endwin();
    return 0;
}