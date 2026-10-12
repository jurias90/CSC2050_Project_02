/*
 *File Name: word_count.c
 *Owner: jurias04
 *Last Modified On: Oct 1 11:28
 */
#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '
#define ENDLINE '\n'

void wordCountAtHome(int* lWC, int* wWC, int* cWC, FILE* fp){
	int currentChar = fgetc(fp);
	int inWord = 0;
	while(currentChar != EOF){
		switch (currentChar){
			case SPACE:
				if(inWord) (*wWC)++;
				inWord = 0;
				break;
		        case ENDLINE:
				if(inWord) (*wWC)++;
				(*lWC)++;
				inWord = 0;
				break;
			default:
				inWord = 1;
		}
		(*cWC)++;
		currentChar = fgetc(fp);
	}
	if(inWord) (*wWC)++;

}

int main(int argc, char *argv[])  {
	//This is an exit clause in case more than one argument is added since only 1 argument is needed.
	if(argc >2){
		printf("Error: You entered too many arguments. Please only use 1 argument for file name.\n");
		exit(1);
	}

	int lineCount, wordCount, charCount;
	FILE* fp = NULL;
	
	if(argc == 2){
		fp = fopen(argv[1],"r");
		if(fp == NULL){
			printf("Error: The file \"%s\" failed to open. It may be corrupt, lack permissions, is in another directory or doesnt exists. Please try again.\n", argv[1]);
			exit(2);
		}
	}else{
		fp = stdin;
	}
	
	lineCount = wordCount = charCount = 0;

	wordCountAtHome(&lineCount,&wordCount, &charCount,fp);

	printf("Line Count: %d, Word Count: %d, Character Count: %d\n", lineCount, wordCount, charCount);

	if(fp != stdin){
		fclose(fp);
	}

	return 0;
}
