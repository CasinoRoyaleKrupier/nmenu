#include <ncurses.h>

int main()
{
    initscr();

    printw("hello world");

    getch();

    endwin();
    return 0;
}