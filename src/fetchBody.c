#include "fetchBody.h"
#include <curl/curl.h>

void fetchBody(char url[256]) {
    CURL *curl = curl_easy_init();
    CURLcode result;

    FILE *f = fopen("data","wb");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);

    result = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    fclose(f);
}
