/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"



int b=0;
int cursorMX;
int cursorMY;



double xa5[]={80-b,110,210,240+b,210,110}; double ya5[]={525,545+b,545+b,525,505-b,505-b};
double xa4[]={80,110,210,240,210,110}; double ya4[]={425,445,445,425,405,405};
double xa3[]={80,110,210,240,210,110}; double ya3[]={325,345,345,325,305,305};
double xa2[]={80,110,210,240,210,110}; double ya2[]={225,245,245,225,205,205};
double xa1[]={80,110,210,240,210,110}; double ya1[]={125,145,145,125,105,105};
double x2=20,x3=60,x4=90,y2=125,y4=225,y5=325,y6=425,y7=525,y8=105,y9=145;



char pc[10][30]={"pc\\3.bmp","pc\\1.bmp","pc\\2.bmp"};
//char button[10][20] ={"button\\7.bmp"};
int index=0;
int l=0,v=0;

bool musicOn = true;

/*
	function iDraw() is called again and again by the system.
*/


void iDraw()
{
	//place your drawing codes here

		if(index == 0){

		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);
	}

	iClear();




	iShowBMP(0,0,pc[index]);




	if(index == 1){

	//iLoadImage("");


		/*if(musicOn){
		musicOn = true;
		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);
		}*/

		//iShowBMP(0,0,menu);
		//iShowBMP2(500,500,button[0],255);
    iSetColor(255, 100, 10);
	iLine(x2,y2,x2,y7);
	iLine(x2,y2,x3,y2);
	iLine(x2,y4,x3,y4);
	iLine(x2,y5,x3,y5);
	iLine(x2,y6,x3,y6);
	iLine(x2,y7,x3,y7);


	iLine(x3,y2,x4,y8);
	iLine(x3,y2,x4,y9);
	iLine(x3,y4,x4,y8+100);
	iLine(x3,y4,x4,y9+100);
	iLine(x3,y5,x4,y8+200);
	iLine(x3,y5,x4,y9+200);
	iLine(x3,y6,x4,y8+300);
	iLine(x3,y6,x4,y9+300);
	iLine(x3,y7,x4,y8+400);
	iLine(x3,y7,x4,y9+400);


	iText(1150,20,"F12:Stop Music",GLUT_BITMAP_9_BY_15);
	iText(1150,5,"F11:Play Music",GLUT_BITMAP_9_BY_15);


	iFilledPolygon(xa5,ya5,6);
	iSetColor(0,0,0);
	iText(125,518,"START",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255, 100, 10);
	iFilledPolygon(xa4,ya4,6);
	iSetColor(0,0,0);
	iText(110,418,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255, 100, 10);
	iFilledPolygon(xa3,ya3,6);
	iSetColor(0,0,0);
	iText(110,318,"RECORDS",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255, 100, 10);
	iFilledPolygon(xa2,ya2,6);
	iSetColor(0,0,0);
	iText(110,218,"CREDITS",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255, 100, 10);
	iFilledPolygon(xa1,ya1,6);
	iSetColor(0,0,0);
	iText(125,118,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(index==2 )
	{
		if(v==0)
		PlaySound(0,0,0);
	}


	if(index==0){

		/*if(musicOn){
			musicOn = false;
		 PlaySound(0,0,0);
		}*/
	   iSetColor(0,225,0);
	   iText(270,135,"Loading.......",GLUT_BITMAP_HELVETICA_18);
	   iRectangle(270,100,700,25);

	     if(l==100) iFilledRectangle(270,100,l+100,25);
		 else if(l==200)iFilledRectangle(270,100,l,25);
		 else if(l==300) iFilledRectangle(270,100,l,25);
		 else if(l==400) iFilledRectangle(270,100,l,25);    //For loading....
		 else if(l==500) iFilledRectangle(270,100,l,25);
		 else if(l==600) iFilledRectangle(270,100,l,25);
		 else if(l==700) iFilledRectangle(270,100,l,25);
		 else if (l==800) index=1;


	}










}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	//LEFT MOUSE:
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    if((mx>= 80 && mx<= 200) && (my>= 105 && my<= 145))
		{
			exit(0); //EXIT
		}

		else if((mx>= 80 && mx<= 240) && (my>= 205 && my<= 245))
		{
			index = 5; //CREDITS
		}
		else if((mx>= 80 && mx<= 240) && (my>= 305 && my<= 345))
		{
			index = 4; //RECORDS
		}
		else  if((mx>= 80 && mx<= 240) && (my>= 405 && my<= 445))
		{
			index = 3; //RULES
		}
		else if((mx>= 80 && mx<= 240) && (my>= 505 && my<= 545))
		{
			index = 2; //START
		}


		//RIGHT MOUSE:

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/





void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);
		iPauseTimer(0);
		v=1;
	}
	if(key == 'r')
	{
		v=0;
		iResumeTimer(0);
	}

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here

	if(key == GLUT_KEY_F12)
	{
		if(index == 1){
			if(musicOn){
		PlaySound(0,0,0);
			}
		}
	}

	if(key == GLUT_KEY_F11)
	{
		if(index == 1){
			if(musicOn){

		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);

			}
		}
	}

	if(key == GLUT_KEY_HOME){

		index = 1;
		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);

	}



}

void iPassiveMouse(int mx,int my){

	//cursorMX=mx;
	//cursorMY=my;


	if(index==1){
	    if((mx>= 80 && mx<= 240) && (my>= 505 && my<= 545)){

		 b+=30;

	    }
	}


}

void load(){
	l+=100;
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(1000,load);

	iInitialize(1280, 720, "BallDemo");

	iStart();
	return 0;
}
