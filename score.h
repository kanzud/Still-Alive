#include "Character.h"

void files();
int I =0;
int N[100];
char Name[100][100],Score[100][100];
char gamePage[2][30]={"gamePage\\1.bmp","gamePage\\input.bmp"};
int IndexNumber = 0;
char enternamestr[1000];

void takeName(char key){
	
		enternamestr[IndexNumber] = key;
		if (IndexNumber <= 25) IndexNumber++;
		enternamestr[IndexNumber] = '\0';
		puts(enternamestr);
}

void writeName(){
  FILE *out = fopen("score.txt", "a");
  fprintf(out,"\n");
  fprintf(out,"%s",enternamestr);
  fclose(out);
}

void writeScore(){
  FILE *aww = fopen("score.txt", "a");
  fprintf(aww," ");
  fprintf(aww,"%d",xxx);
  fclose(aww);
  files();
}



void namePage(){

	 iShowBMP(0,0,gamePage[1]);
	 iText (400,250,enternamestr,GLUT_BITMAP_TIMES_ROMAN_24);


}

typedef struct player player;
struct player{
	char name[100];
	int score;

};

player t[10];


void sort(){
	
	int j=0,temp;
	char tempName[100],tempScore[100];

	FILE *fc = fopen("score.txt", "r");
//	player p;

	
	while(fscanf(fc, "%s %d", t[j].name, &t[j].score) != EOF)
    {		
		j++;
    }
    fclose(fc);


	for (int c = 0 ; c < 10 - 1; c++)
		for(int j = 0 ; j < 10 - c - 1; j++)
		{
			if( t[j].score < t[j+1].score)
							{
								temp = t[j].score;
								t[j].score = t[j+1].score;
								t[j+1].score = temp;

								strcpy( tempName , t[j].name);
								strcpy( t[j].name , t[j+1].name);
								strcpy( t[j+1].name , tempName);

								strcpy( tempName , Name[j]);
								strcpy( Name[j] ,Name[j+1] );
								strcpy( Name[j+1] , tempName);

								strcpy( tempScore , Score[j]);
								strcpy( Score[j] ,Score[j+1] );
								strcpy( Score[j+1] , tempScore);
							}
		}
}


void showScore(){
	
	iSetColor(255,0,0);
	int y=600;
	for(int j=0,y=600;j<I;j++,y-=40){
		iText(100,y,Name[j],GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320,y,Score[j],GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void files(){

	
	FILE *fp = fopen("score.txt", "r");
//	player p;
	I=0;
	
	while(fscanf(fp, "%s %s", Name[I],Score[I]) != EOF)
    {		
		I++;
    }
    fclose(fp);
	sort();
}


void onScreenScore(){

	point =xxx;
    char b[3];
    b[0]='\0';
    b[1]='\0';
    b[2]='\0';
    b[1]=(point%10)+48;
    point=point/10;
    b[0]=point+48;
	
	iText(1100,650,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1200,650,b,GLUT_BITMAP_TIMES_ROMAN_24);
  //  puts(b);
    
}



