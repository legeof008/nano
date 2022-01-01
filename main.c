/*Author: Maciej Michalski
  git: legeof008 */
#include <ncurses.h>
#include <stdio.h>
#include "nano.h"
int main(int argc, char** argv)
{
    int row,col;
    int ch;

    initscr();
    start_color();
    cbreak;
    getmaxyx(stdscr,row,col);

    keypad(stdscr, TRUE);
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    
    t_panel top = init_t_panel(col,0,"cipka");
    refresh();
    print_t_panel(top,TRUE);
    while((ch = getch()) != KEY_F(1))
    {
        
    }
    
}