#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <ncurses.h>

int main(void) {
    CURL *curl = curl_easy_init();
    CURLcode result;
    FILE *f = fopen("data","wb");
    curl_easy_setopt(curl, CURLOPT_URL, "http://marcelkaemper.deinsh.eu");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
    result = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return 0;
}