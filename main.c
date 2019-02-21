#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "src/fetchBody.h"
#include "src/getTagContent.h"

int main(void) {
    int h,w;
    char url[250];

    getTagContent();

    initscr();
    getmaxyx(stdscr, h, w);
    
    WINDOW *win = newwin(h,w,0,0);

    noecho();
    keypad(stdscr, TRUE);

    // Draw box around the window
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if((i==0) || (i==h-1) || (i==h-3)){
                mvwaddch(win,i,j,ACS_BLOCK);
            }else{
                mvwaddch(win, i, 0, ACS_BLOCK);
                mvwaddch(win, i, w-1, ACS_BLOCK);
            }
        }
    }

    refresh();
    wrefresh(win);

    int cursorPos = 0;
    wmove(win, h-2, cursorPos+2);

    for(;;) {
        int c = getch();
        if(c == 10){
            break;
        }
        else if(c == KEY_BACKSPACE){
            url[cursorPos] = '\0';
            mvwdelch(win, h-2, cursorPos+1);
            cursorPos -= 1;
        }
        else{
            url[cursorPos] = c;
            mvwaddch(win, h-2, cursorPos+2, url[cursorPos]);
            cursorPos += 1;
        }
        wrefresh(win);
    }

    endwin();

    FILE *fp = fopen("out", "w");
    fprintf(fp, "%s%s", url, "\n");

    fetchBody(url);

    return 0;
}