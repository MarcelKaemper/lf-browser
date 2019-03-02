#include "rmWhitespaces.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void rmWhitespaces() {
	FILE *fp;
	FILE *fpp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char linebuffer[128] = {'\0'};
	int bufferPos = 0;
	bool active = true;

	fp = fopen("data", "r");

	while ((read = getline(&line, &len, fp)) != -1) {
		for(int i = 0; i<read; i++){
			if(active){
				if(!isspace(line[i])){
					active = false;
					linebuffer[bufferPos] = line[i];
					bufferPos += 1;
				}
			}else{
				linebuffer[bufferPos] = line[i];
				bufferPos += 1;
			}
		}

		/* linebuffer[bufferPos] = '\n'; */
		fpp = fopen("test_new", "a");
		fprintf(fpp, linebuffer);
		fclose(fpp);
		for(int i = 0; i<sizeof(linebuffer);i++){
			linebuffer[i] = '\0';
		}
		bufferPos = 0;
		active = true;
	}
	fclose(fp);
}
