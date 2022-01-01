#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	char message [] = "Kliknieto Enter";
	char* ch = malloc(sizeof(ch)*30);
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
	while(1)
	{
		ck = getch();
		refresh();
		if(ck == KEY_F(2))
		{
			current_row++;
			mvprintw(current_row,current_col,message);
		}
		*(ch+current_col) = ck;
		current_col++;
		mvprintw(current_row,current_col,(ch+current_col-1));
		refresh();
		mvprintw(row-2,0,"This screen has %d rows and %d columns, number of characters is: %d\n",current_row,current_col,current_col);
		move(current_row,current_col+1);
	}
	printw("Przerwano prace");

	
	getch();
	endwin();
	free(ch);

	return 0;
}
