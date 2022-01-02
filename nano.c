/*Author: Maciej Michalski
  git: legeof008 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nano.h"

t_panel init_t_panel(int width, char *filename)
{
    t_panel output;
    output.filename = filename;
    output.program_name = PROGRAM_NAME_DEFAULT;
    output.version = CURRENT_VERSION_DEFAULT;
    output.width = width;
    output.status = FALSE;
    output.window = NULL;
    return output;
}
w_panel init_w_panel(int height, int width)
{
    w_panel output;
    output.buffer = malloc(DEFAULT_BUFFER_SIZE * sizeof(char));
    output.bufferIdx = 0;
    output.width = width;
    output.height = height;
    output.w_window = NULL;
    return output;
}
b_panel init_b_panel()
{
    b_panel output;
    return output;
}
void refresh_w_panel(w_panel *panel, int current_x, int current_y)
{

    int width = panel->width;
    int height = panel->height;
    WINDOW *window = newwin(height, width, current_y, current_x);
    if (panel->w_window != NULL)
        delwin(panel->w_window);
    panel->w_window = window;
    wrefresh(window);
}
void print_t_panel(t_panel *panel, bool flag)
{
    WINDOW *window = newwin(0, panel->width, 0, 0);
    int i, j;
    int width;
    char *filename;
    char *program_name;
    char *version;

    filename = panel->filename;
    program_name = panel->program_name;
    version = panel->version;
    width = panel->width;

    int l, m;

    if (flag == TRUE)
    {
        wattron(window, A_STANDOUT);
        l = strlen(program_name);
        m = strlen(filename);

        mvwprintw(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, 0, program_name);
        mvwaddch(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, l, ' ');
        mvwprintw(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, l + 1, version);

        mvwaddch(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, l + 4, ' ');
        for (i = l + 4; i < width / 2; ++i)
            mvwaddch(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, i, ' ');

        mvwprintw(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, i, filename);
        for (j = i + m; j < width - 9; j++)
            mvwaddch(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, j, ' ');

        if (panel->status)
            mvwprintw(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, j, DEFAULT_MODIFIED);
        else
            mvwprintw(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, j, DEFAULT_UNMODIFIED);
        mvwaddch(window, DEFAULT_TOP_PANEL_PRINTING_HEIGHT, j + 9, ' ');

        wattroff(window, A_STANDOUT);
        if (panel->window != NULL)
            delwin(panel->window);
        panel->window = window;
        wrefresh(window);
    }
}