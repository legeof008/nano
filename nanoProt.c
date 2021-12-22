#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)
{
	char* ch = malloc(sizeof(ch)*5);
	char ck;
	int current = 0;

    int row,col;
    char mesg[]="Just a string";

	initscr(); /* Start curses mode */
    getmaxyx(stdscr,row,col);
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
    mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
	cbreak(); /* Turning off line buffering */
	keypad(stdscr,TRUE);
	noecho(); /*letters dont repeat*/


	refresh();
	getch();
	endwin();

	return 0;
}
