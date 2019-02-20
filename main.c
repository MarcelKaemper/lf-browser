#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "src/fetchBody.h"

int main(void) {
    int h,w;
    char url[250];

    initscr();
    getmaxyx(stdscr, h, w);
    WINDOW *win = newwin(h,w,0,0);

    // Draw box around the window
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if((i==0) || (i==h-1)){
                mvwaddch(win,i,j,ACS_BLOCK);
            }else{
                mvwaddch(win, i, 0, ACS_BLOCK);
                mvwaddch(win, i, w-1, ACS_BLOCK);
            }
        }
    }

    refresh();
    wrefresh(win);

    char c = getch();

    endwin();

    if(c == '1'){
        strcpy(url,"http://marcelkaemper.deinsh.eu");
    }
    
    fetchBody(url);

    return 0;
}