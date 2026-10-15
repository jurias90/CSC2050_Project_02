/*
 *File Name: unique.c
 *Owner: jurias04
 *Last Modified On: Oct 6 09:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uniqueCompAtHome(FILE* fp){
	char* lineRead = NULL;
	char* lineBefore = NULL;
	size_t lineSize = 0;
	size_t lineBeforeSize = -1;

	while(getline(&lineRead, &lineSize, fp) != -1){
		//This if check is to just make sure that the comparison doesnt happen during the first line
		//and that it doesnt even go through the print if the lines arent equal length
		if(lineBefore == NULL || strcmp(lineBefore,lineRead) != 0 ){
			printf("%s", lineRead);
			char* tmpPtr = lineBefore;

			lineBeforeSize = lineSize;
			lineBefore = lineRead;
			
			lineRead = tmpPtr;
		}	
	}

	free(lineRead);
	free(lineBefore);	
}

int main(int argc, char *argv[])  {
	if(argc > 2){
		printf("ERROR: There are more arguments than allowed. Please use only 1(Filename) or no argument.");
		exit(1);
	}

	FILE* fp = NULL;

	if(argc == 2){
		fp = fopen(argv[1],"r");
		if(fp == NULL){
			printf("ERROR: Could not open file due to corruption, wrong file name or wrong file location. Please try again.");
			exit(2);
		}
	}else{
	       	fp = stdin;
	}

	uniqueCompAtHome(fp);

	if(fp != stdin){
		fclose(fp);
	}
	return 0;
}
