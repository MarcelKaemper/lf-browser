#include "getTagContent.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getTagContent(){
    char input[20] = "<h1>header</h1>";
    char content[10];
    char name[10] = {'\0'};

    for(int i = 0; i<sizeof(input); i++){
	if((input[i] == '<') && (input[i+1] != '/')){
		printf("Open\n");
		int index = i+1;
		int pos = 0;
		while(input[index] != '>'){
			name[pos] = input[index];
			printf("%c",input[index]);
			pos+=1;
			index+=1;
		}
	}
	if((input[i] == '<') && (input[i+1] == '/')){
		printf("Close\n");
	}
    }

    printf("%s\n", name);
}
