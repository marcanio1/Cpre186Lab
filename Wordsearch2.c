#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 15
#define DEBUG 1   // set to 0 to disable debug output
#define temp1 0
#define temp2 0
int height, width;
char MAZE[temp1][temp2];
int readWords(char* wl[MAXWORDS], char* filename);	
void draw_character(int y, int x, char use);
void trimws(char* s);
int graphwords(int height, int width, char* wl[MAXWORDS],int wordCount);
int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	
	//int len = strlen(wordlist[1]);
	printf("Enter the height: ");
	scanf("%d", &height);
	//printf("%d", len);
	printf("Enter the width: ");
	scanf("%d", &width);
	wordCount = readWords(wordlist, argv[1]);


	
	if (DEBUG) {
		//printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);
			}
		printf("\n");
		
		}

	initscr();
	refresh();
	graphwords(height,width,wordlist, wordCount);
	int xVal = 1; 
	int yVal = 0;
	for(int i = 0; i < wordCount; i++) 
	{
		mvprintw(yVal, xVal, "%s", wordlist[i]);
		refresh();
		xVal += 15;
		if(xVal >= 75)
		{
			yVal++;
			xVal=1;
		}
		refresh();
	}
	
	
	
	while(1){
		
	}
	
	endwin();
	return 0;
	}
int graphwords(int height, int width, char* wl[MAXWORDS], int wordCount){
	int i, j;
	int num= 0;
	int randomx, randomy;
	
	for (i =0; i< height; i++)
		for( j =0; j< (width*2); j++){
			mvprintw(i+5, j ,"# ");
			j+=1;
	
		}
		
	/* switch(num){
		case 0:
		for(i =0; i< wordCount ; i++){
		randomx= (rand() % width);
		randomy =(rand() % height);
		}
		for
		
		
		break;
		
		
		
		
		
		
	} */
		
	for(i =0; i< wordCount ; i++){
		check();
		randomx= (rand() % width);
		randomy =(rand() % height);
		int length = strlen(wl[i]);
		for(j = 0; j < length ; j++){
			check();
			if (MAZE[randomx][randomy + j] != '#'){
				randomx= (rand() % width);
				randomy =(rand() % height);
				j -=1;
			}
			else
					mvprintw(randomy,randomx,wl[i]); 
			
		}
	
		
	}
	
}


void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
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
	
void draw_character(int y, int x, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

void check(void){
	int i, j;
	for( i = 0; i< height ; i++)
		for(j = 0; j< width; j ++){
			mvaddch(i,j,MAZE[i][j]) ;
			refresh();
		}
}