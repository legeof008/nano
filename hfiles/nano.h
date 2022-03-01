/*Author: Maciej Michalski
  git: legeof008 */
#ifndef _NANO_H_
#define _NANO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <string.h>

#define CURRENT_VERSION_DEFAULT "0.1"
#define PROGRAM_NAME_DEFAULT "nano"
#define DEFAULT_MODIFIED "MODIFIED "
#define DEFAULT_UNMODIFIED "         "
#define DEFAULT_TOP_PANEL_HEIGHT 1
#define DEFAULT_TOP_PANEL_PRINTING_HEIGHT 0
#define DEFAULT_BUFFER_SIZE 20
#define CURSOR_X_DEFAULT_VAL 0
#define CURSOR_Y_DEFAULT_VAL 0

#pragma pack(push,1)

typedef struct bottom_panel_struct{
    /* 
        skróty klawiszowe,
        czy plik jest nowy czy nie,
    */
}b_panel;
typedef struct top_panel_struct
{
    WINDOW* window;
    char* filename;
    char* program_name;
    char* version;
    bool status;
    int width;
}t_panel;
typedef struct workspace_panel_struct{
    WINDOW* w_window;
    char* buffer;
    int bufferIdx;
    int width;
    int height;
}w_panel;

#pragma pack(pop)

t_panel init_t_panel(int width, char *filename);
b_panel init_b_panel();
w_panel init_w_panel(int height, int width);
/* odświeża panel górny*/
void print_t_panel(t_panel* panel, bool flag);
/* zmienia odpowiednio wartości kursora*/
void change_cursor_position(int , int*, int*, int, int,w_panel*);
/* wypisywanie aktualnego bufforu */
void read_lines_from_file(char*, int*, w_panel*);
/* sprawdzanie czy plik istnieje */
int check_if_file_exists(char* );
#endif