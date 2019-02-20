#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <ncurses.h>
#include "src/fetchBody.h"

int main(void) {
    char url[250] = "http://marcelkaemper.deinsh.eu";
    fetchBody(url);

    return 0;
}