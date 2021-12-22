#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	char* ch = malloc(sizeof(ch)*5);
	char ck;
	int current_row,current_col;
	int col,row;

	initscr(); /* Start curses mode */
	getmaxyx(stdscr,row,col);
	cbreak(); /* Turning off line buffering */
	keypad(stdscr,TRUE);
	noecho(); /*letters dont repeat*/

	printw("Wpisz dowolny ciag znakow do prompta\n");
	current_row=1;
	current_col=0;
	while(ck != KEY_ENTER)
	{
		ck = getch();
		*(ch+current_col) = ck;
		current_col++;
		mvprintw(current_row,current_col,(ch+current_col-1));
		refresh();
		if(ck == KEY_ENTER)
		{
			current_row++;
		}
		mvprintw(row-2,0,"This screen has %d rows and %d columns, number of characters is: %d\n",row,col,current_col);
		move(current_row,current_col+1);
	}
	printw("Przerwano prace");

	refresh();
	getch();
	endwin();

	return 0;
}
