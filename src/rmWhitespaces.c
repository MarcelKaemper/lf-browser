#include "rmWhitespaces.h"
#include <stdlib.h>
#include <stdio.h>

void rmWhitespaces() {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char linebuffer[128] = {'\0'};
	int bufferPos;

	fp = fopen("test", "r");

	while ((read = getline(&line, &len, fp)) != -1) {
		bufferPos = 0;
		for(int i = 0; i<sizeof(line); i++){
			if(line[i] != ' '){
				linebuffer[bufferPos] = line[i];
				bufferPos+=1;
			}	
		}
	}
	printf("%s\n", linebuffer);
	fclose(fp);
}
