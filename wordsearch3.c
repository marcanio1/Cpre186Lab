#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 15
#define temp1 0
#define temp2 0
int height, width;
char maze[temp1][temp2];
int readWords(char wl[MAXWORDS], char* filename);


int main(){
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	
	printf("Enter the height: ");
	scanf("%d", &height);
	printf("Enter the width: ");
	scanf("%d", &width);
	
	
	graphwords(height,width,wordlist, wordCount);
	
	
}
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
	
int graphwords(int height, int width, char wl[MAXWORDS], int wordCount){
	int i, j;
	int num= 0;
	int randomx, randomy;
	
	for (i =0; i< height; i++)
		for( j =0; j< (width*2); j++){
			
			j+=1;
	
		}
		
}