#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "src/fetchBody.h"

int main(void) {
    char url[250];

    initscr();
    WINDOW *win = newwin(10,10,10,10);

    char c = getch();

    endwin();

    if(c == '1'){
        strcpy(url,"http://marcelkaemper.deinsh.eu");
    }
    
    fetchBody(url);

    return 0;
}