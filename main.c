/*Author: Maciej Michalski
  git: legeof008 */
#include <ncurses.h>
#include <stdio.h>
#include "nano.h"

int main(int argc, char **argv)
{
  int row, col;
  int ch;
  int currx = 0;
  int curry = 1;

  initscr();
  start_color();
  cbreak();
  getmaxyx(stdscr, row, col);

  t_panel top = init_t_panel(col, "filename");
  w_panel workspace = init_w_panel(row - 2, col);
  keypad(stdscr, TRUE);
  noecho();
  refresh();
  // graphical setup
  print_t_panel(&top, TRUE);
  move(1, 0);

  while ((ch = getch()) != KEY_F(1))
  {
    switch (ch)
    {
    case KEY_LEFT:
      if (currx > 0)
      {
        currx--;
      }
      else
      {
        currx = col - 1;
      }
      print_t_panel(&top, TRUE);
      refresh_w_panel(&workspace, currx, curry);
      break;
    case KEY_RIGHT:
      if (currx < col - 1)
      {
        currx++;
      }
      else
      {
        currx = 0;
      }
      print_t_panel(&top, TRUE);
      refresh_w_panel(&workspace, currx, curry);
      break;
    case KEY_UP:
      if (curry > 1)
        curry--;
      print_t_panel(&top, TRUE);
      refresh_w_panel(&workspace, currx, curry);
      break;
    case KEY_DOWN:
      if (curry < row)
        curry++;
      print_t_panel(&top, TRUE);
      refresh_w_panel(&workspace, currx, curry);
      break;
    }
  }
  endwin();

  return 0;
}
