/*Author: Maciej Michalski
  git: legeof008 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nano.h"

t_panel init_t_panel(int x, int y, char *filename)
{
    t_panel output;
    output.filename = filename;
    output.program_name = PROGRAM_NAME_DEFAULT;
    output.version = CURRENT_VERSION_DEFAULT;
    output.x = x;
    output.y = y;
    output.status = TRUE;
    return output;
}
b_panel init_b_panel()
{
    b_panel output;
    return output;
}
void print_t_panel(t_panel panel, bool flag)
{

    int i, j;
    int x, y;
    char* filename;
    char* program_name;
    char* version;
    
    filename = panel.filename;
    program_name = panel.program_name;
    version = panel.version;
    x = panel.x;
    y = panel.y;

    int l,m;

    if (flag == TRUE)
    {
        attron(A_STANDOUT);
        //dodajemy nazwę programu plus wersję
        l = strlen(program_name);
        m = strlen(filename);
        mvprintw(0,0,program_name);
        mvaddch(0,l,' ');
        mvprintw(0,l+1,version);
        mvaddch(0,l+4,' ');
        for(i = l + 4 ; i < x/2; ++i)
            mvaddch(y,i,' ');
        mvprintw(y,i,filename);
        for(j = i+m; j< x-9; j++)
            mvaddch(y,j,' ');
        if(panel.status)
            mvprintw(y,j,"MODIFIED ");
        else
            mvprintw(y,j,"         ");
        mvaddch(y,j+9,' ');

        attroff(A_STANDOUT);
        move(1,0);
        /*m = strlen(version);
        mvprintw(y,i,version);*/
        refresh();
    }
}