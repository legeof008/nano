/*Author: Maciej Michalski
  git: legeof008 */
#ifndef _NANO_H_
#define _NANO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define CURRENT_VERSION_DEFAULT "1.0"
#define PROGRAM_NAME_DEFAULT "GNU nano-prot"

#pragma pack(push,1)

typedef struct bottom_panel_struct{
    /* 
        skróty klawiszowe,
        czy plik jest nowy czy nie,

    */
}b_panel;
typedef struct top_panel_struct
{
    char* filename;
    char* program_name;
    char* version;
    bool status;
    int x,y;
}t_panel;

#pragma pack(pop)

t_panel init_t_panel(int x, int y, char *filename);
b_panel init_b_panel();
void print_t_panel(t_panel panel, bool flag);
#endif