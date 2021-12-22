#include<stdio.h>
#include<ncurses.h>

int main(int argc, char** argv)
{
	initscr(); /* Start curses mode */
	printw("Hello World !"); /* : D */
	refresh();
	getch();
	endwin();
	return 0;
}
