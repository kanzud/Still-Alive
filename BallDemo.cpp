
#include "AllHeader.h"

int n=0,x=0;
int i=-1,k=-1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
char sss[1][20]={"gamePage\\1.bmp"};
int index=0;
int v=0; // l for loading page v for music on off
bool musicOn = true; // just testing
int state=-1;
char save[3][30] ={"saving\\1.bmp","saving\\2.bmp","saving\\3.bmp"};
////////////////////////////////////////////////////////////////////////////////////////////////////////
void call(){
	if(n==1 && i<8)
		i = i+1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void iDraw()
{
	
	iClear();
	Sound(index);
	picture(index);
	/////////////////////////////////////
	if(index==0){
		  Load();
		  if(l == 800) index = 1;
	}
	if(index == 1){
		Button();
	}
	if(index==2 )
	{ 
		iText(1100,100,"Main Menue: HOME");
		if(k==1){
			n=1;                      //////////game page/////////      
		}
		story(i,x);

		if(state==1){
			namePage();
		}
		if(state==2){
			iShowBMP(0,0,sss[0]);
			Shoot();
			Jump();
			randomEnemyTreesMovement();
			collusion();
			onScreenScore();
		}
	}
	if(index == 3){
		iText(1100,100,"Main Menue: HOME");
	}
	if(index == 4){
		iText(1100,100,"Main Menue: HOME");
		showScore();
	}
	if(index == 5){
		iText(1100,100,"Main Menue: HOME");
		Credit(i);
		if(i==3)
			index = 2;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iMouse(int button, int state, int mx, int my)
{
	//LEFT MOUSE:
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    if((mx>= 80 && mx<= 240) && (my>= 105 && my<= 145) && (index == 1))
		{
			PlaySound("music\\click.wav",NULL,SND_ASYNC);
			exit(0); //EXIT
		}
		else if((mx>= 80 && mx<= 240) && (my>= 205 && my<= 245) && (index == 1))
		{
			//PlaySound("music\\click.wav",NULL,SND_ASYNC);
			index = 5; //CREDITS
			i = -1;
			n = 1;
		}
		else if((mx>= 80 && mx<= 240) && (my>= 305 && my<= 345)&& (index == 1) )
		{
			PlaySound("music\\click.wav",NULL,SND_ASYNC);
			index = 4; //RECORDS
            files();
		}
		else  if((mx>= 80 && mx<= 240) && (my>= 405 && my<= 445)&& (index == 1) )
		{
			PlaySound("music\\click.wav",NULL,SND_ASYNC);
			index = 3; //CONTROL
		}
		else if((mx>= 80 && mx<= 240) && (my>= 505 && my<= 545)&& (index == 1) )
		{
			PlaySound("music\\click.wav",NULL,SND_ASYNC);
			i = -1;
			index = 2; //START
		}

	}
	//RIGHT MOUSE:
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}
///////////////////////////////////////////
void iMouseMove(int mx, int my)
{
	//place your codes here
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iPassiveMouse(int mx,int my){

   if(index==1){
	   if((mx>= 80 && mx<= 230) && (my>= 500 && my<= 550)){
		    b=5;
	   }
	   else{
			b=0;

	   }
	   if((mx>= 80 && mx<= 230) && (my>= 400 && my<= 450)){
		   c=5;
	   }
	   else{
		   c=0;
	   }
	   if((mx>= 80 && mx<= 230) && (my>= 300 && my<= 350)){
		   d=5;
	   }
	   else{
		   d=0;
	   }
	   if((mx>= 80 && mx<= 230) && (my>= 200 && my<= 250)){
		   e=5;
	   }
	   else{
		   e=0;
	   }
	   if((mx>= 80 && mx<= 230) && (my>= 100 && my<= 150)){
		   f=5;
	   }
	   else{
		   f=0;
	   }
	   
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iKeyboard(unsigned char key)
{
	if(key=='b'){
		writeScore();
		index = 1;
		state = -1;
	}
	if(key=='s'){
	 saveGame();
	}
	if(key=='\r'){
		writeName();
		state =2;
		PlaySound("music\\enter.wav",NULL,SND_ASYNC);
	}
	if(key==' '){
		pressSpacetoJump();
		PlaySound("music\\jump.wav",NULL,SND_ASYNC);
	}
	if(key=='f'){
		pressFtoShoot();
		PlaySound("music\\gun.wav",NULL,SND_ASYNC);
	}
	if(key=='c'){
	   h=1;
	}
///////////////////////////////////////////////////////////////name input page/////////////////////////////////
	if(key != '\b'){

		takeName(key);
		
	}
	else {
		if (IndexNumber <= 0) IndexNumber = 0;
		else IndexNumber--;
		enternamestr[IndexNumber] = '\0';
		PlaySound("music\\backspace.wav",NULL,SND_ASYNC);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_F12)
	{
		if(index == 1){
		PlaySound(0,0,0);
		}
	}
	if(key == GLUT_KEY_F11)
	{
		if(index == 1){
		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if(key == GLUT_KEY_HOME){
		//n=0;
		//state = -1;
		index = 1;
		PlaySound("music\\1.WAV",NULL, SND_LOOP | SND_ASYNC);
		x=0;
	}
	if(key == GLUT_KEY_F1){
		k = 1;
		x=1;
		i = -1;
		PlaySound("storySound\\s.wav",NULL,SND_ASYNC);
	}
	if (key == GLUT_KEY_F2 ){
		state=1;
	}
	if (key == GLUT_KEY_F3 ){
		loadGame();
		state=2;
	}
	if(key== GLUT_KEY_RIGHT){
		pressRight();
		PlaySound("music\\walk.wav",NULL,SND_ASYNC);
	}
	if(key== GLUT_KEY_LEFT){
		pressLeft();
		PlaySound("music\\walk.wav",NULL,SND_ASYNC);
	}
}
////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setEnemyTrees();

	iSetTimer(50,shoot);
	iSetTimer(25,change);
	iSetTimer(300,load);
	iSetTimer(8000,call);

	iInitialize(1280, 720, "Still Alive");
	iStart();

	return 0;
}
