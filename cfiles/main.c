/*Author: Maciej Michalski
  git: legeof008 */
#include "../hfiles/nano.h"

int main(int argc, char **argv)
{
  if (argc <= 1)
  {
    printf("nano : No file name given, please specify filename !");
    exit(EXIT_FAILURE);
  }
  else if (argc > 2)
  {
    printf("nano : Too many elements. Specify single filename !");
    exit(EXIT_FAILURE);
  }

  bool modified_flag = TRUE;
  /* zmieniona jeśli został stworzony nowy plik lub zmodyfikowany istniejący*/
  int row, col;
  /* wiersze i kolumny okna*/
  int linecounter = CURSOR_Y_DEFAULT_VAL;
  /* licznik wypisywanych linii*/
  int ch;
  /*zmienna pomocnicza przy wyczytywania klawiszy wejściowych*/
  int currx = CURSOR_X_DEFAULT_VAL;
  /*początkowa zmienna kursora w x oraz niżej w y*/
  int curry = CURSOR_Y_DEFAULT_VAL;

  initscr();
  start_color();
  cbreak();
  getmaxyx(stdscr, row, col);

  t_panel top = init_t_panel(col, "filename");
  w_panel workspace = init_w_panel(row - 2, col);
  keypad(stdscr, TRUE);
  noecho();
  refresh();

  /* wypisanie na ekran linii */
  if (check_if_file_exists(argv[1]) == 0)
  {
    modified_flag = FALSE;
  }
  print_t_panel(&top, modified_flag);
  read_lines_from_file(argv[1], &linecounter, &workspace);
  wmove(workspace.w_window, curry, currx);
  wrefresh(workspace.w_window);
  /* główna pętla programu */
  while ((ch = getch()) != KEY_F(1))
  {
    print_t_panel(&top, modified_flag);
    change_cursor_position(ch, &currx, &curry, col, row, &workspace);
    read_lines_from_file(argv[1], &linecounter, &workspace);
    wmove(workspace.w_window, curry, currx);
    wrefresh(workspace.w_window);
    // print_t_panel(&top, modified_flag);
    // refresh_w_panel(&workspace, currx, curry);
  }
  delwin(workspace.w_window);
  delwin(top.window);
  endwin();

  exit(EXIT_SUCCESS);
}
