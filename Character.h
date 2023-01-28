///////////////////CHARECTER movement variables////////////////////////////////
# define JUMPLIMIT 150
#define TREESNUMBER 1

int xxx=0;
int point=0;
int ii;
int T=1;
char run[12][30]={"run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp","run\\11.bmp","run\\12.bmp","run\\13.bmp"};
char playerStand[5][20]={"shoot\\2.bmp","shoot\\6.bmp"};

int charX=160;
int charY=160;
int charIndex=0;
bool standPosition=true;
int standcount=0;

int T1=0;
char reverseRun[12][30]={"run2\\2.bmp","run2\\3.bmp","run2\\4.bmp","run2\\5.bmp","run2\\6.bmp","run2\\7.bmp","run2\\8.bmp","run2\\9.bmp","run2\\10.bmp","run2\\11.bmp","run2\\12.bmp","run2\\13.bmp"};
char reverseStand[5][20]={"shoot\\3.bmp","shoot\\7.bmp"};
bool reversePosition=true;

char charShoot[10][30]={"shoot\\1.bmp","shoot\\2.bmp","shoot\\4.bmp","shoot\\5.bmp"};

int w=0;
int h=0;
/////////////////////JUMP VARIABLE//////////////////////////////////

char charJump[5][30]={"jump\\10.bmp","jump\\6.bmp"};
char reverseJump[5][30]={"jump2\\10.bmp","jump2\\6.bmp"};
bool jump=false;
bool jumpUp=false;
int jumpIndex=0;
bool revJumpUp=false;

///////////SHOOT VARIABLES///////////////////////////////////////////

int sx[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sy[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int eyf[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int e3=0;
int e1;
int temp=0;
int e2;
int PP,CC;
int u = 0;


///////////////life/////////////////////////////
char Life [6][20] = {"Life\\1.bmp","Life\\2.bmp","Life\\3.bmp","Life\\4.bmp","Life\\5.bmp","Life\\6.bmp"};
int life =0;
char dead[1][20] = {"Dead\\7.bmp"};
////////////////variables for enmy/////////////////////////////////////
char randomEnemyTreeArray[12][20] = {"enemyrun3\\2.bmp","enemyrun3\\3.bmp","enemyrun3\\4.bmp","enemyrun3\\5.bmp","enemyrun3\\6.bmp"};
struct randomtree{
	int tree_x;
	int tree_y;
	int treeIndex;
	bool treeShow;
};
randomtree RandomEnemyTree[TREESNUMBER];

//////////////SHOOT CODE/////////////////////////////

void shoot(){
	for(e2=0; e2<25; e2++){
	  sx[e2]+=eyf[e2]/25;
	  if(sx[e2]>1280){
	     sx[e2]=0;                       ///not in i draw
		 eyf[e2]=0;
	  
	  }
	}
}

void pressFtoShoot(){
	eyf[e3]=780;              ///at keyboard F
	e3++;
	if(e3>24) e3=0;
}

void Shoot(){

		for(e1=0; e1<25; e1++){
			if(eyf[e1]==0){
			  sy[e1]=240;
			}
			

			if(eyf[e1]!=sx[e1]){
			   iShowBMP2(sx[e1]+charX+100,sy[e1],charShoot[3],0);                   ////at idraw state 2
			  
			}
				
		}

}

/////////////////////JUMP/////////////////////////////////////////
void Jump(){
	if(jump){
			if(jumpUp && T==1 && T1==0){
			  iShowBMP2(charX,charY+jumpIndex,charJump[0],0);

			}
			else if(T==1 && T1==0) {
			  iShowBMP2(charX,charY+jumpIndex,charJump[1],0);

			}
		}
		else{
		      if(!standPosition && reversePosition){

			          iShowBMP2(charX,charY,run[charIndex],0);
			          standcount++;
			          if(standcount>=10){
				            standcount=0;
			                charIndex=0;
			                standPosition=true;
			                }
		      }

		      else if(T==1 && T1==0 && h!=1 ){
		              iShowBMP2(charX,charY,playerStand[0],0);
	                  }
			  else if(h==1 && T==1 && T1==0 ){
			          iShowBMP2(charX,charY,playerStand[1],0);
					  h=0;
			          }
		      }
		if(jump){
			   if(revJumpUp && T==0 && T1==1){
			          iShowBMP2(charX,charY+jumpIndex,reverseJump[0],0);

			          }
			   else if(T==0 && T1==1){
			          iShowBMP2(charX,charY+jumpIndex,reverseJump[1],0);

			          }
		}
		else{
		       if(!reversePosition && standPosition){
			          iShowBMP2(charX,charY,reverseRun[charIndex],0);
			          standcount++;
			       if(standcount>=10){
				        standcount=0;
			            charIndex=0;
			            reversePosition=true;

			            }
	            }
		    else if(T1==1 && T==0 && h!=1){
			      iShowBMP2(charX,charY,reverseStand[0],0);
		    }
			else if(h==1 && T1==1 && T==0){
			        iShowBMP2(charX,charY,reverseStand[1],0);
					h=0;
			}
	   }
}

void pressSpacetoJump(){
	if(!jump){
		  jump=true;
		  jumpUp=true;
		  revJumpUp=true;
		  charX+=10;
		}
}

//////////////movement/////////////////////////////////////

void pressRight(){

	    T=1;
		T1=0;

		if(charX>=1180) charX=1180;
		else charX+=10;



		charIndex++;

		if(charIndex>=12)
		{
		   charIndex=0;

		}

		standPosition=false;
}

void pressLeft(){
	    T1=1;
		T=0;
		if(charX<=0) charX=0;
		else charX-=10;

		charIndex++;

		if(charIndex>=12)
		{
		   charIndex=0;

		}
		reversePosition=false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void change(){
	if(jump){
		   if(jumpUp){
		        jumpIndex+=5;

		        if(jumpIndex>=JUMPLIMIT){
		           jumpUp=false;
		           }
	      }
		 else{
		      jumpIndex-=5;
		      if(jumpIndex<0){

		         jump=false;
		         jumpIndex=0;
		      }

		 }
		 if(revJumpUp){
		        jumpIndex+=5;

		        if(jumpIndex>=JUMPLIMIT){
		           revJumpUp=false;
		           }
	      }
		 else{
		      jumpIndex-=5;
		      if(jumpIndex<0){

		         jump=false;
		         jumpIndex=0;
		      }

		 }
	}
//////////////////////////////////enmy tree///////////////////////////////////////////
	for(ii=0;ii<TREESNUMBER;ii++)
	{
		if(xxx>0 && xxx<10)
			RandomEnemyTree[ii].tree_x -= 5;
		if(xxx>=10 && xxx<20)
			RandomEnemyTree[ii].tree_x -= 10;
		else
			RandomEnemyTree[ii].tree_x -= 15;



		if((RandomEnemyTree[ii].tree_x <= 0))
		{
			RandomEnemyTree[ii].tree_x = 1200;
		}
		RandomEnemyTree[ii].treeIndex++;
		if (RandomEnemyTree[ii].treeIndex  >=  5)
			RandomEnemyTree[ii].treeIndex = 0;
	}
}


void randomEnemyTreesMovement(){
	for (ii=0;ii<TREESNUMBER;ii++)
	{
		if(RandomEnemyTree[ii].treeShow)
		{
		iShowBMP2(RandomEnemyTree[ii].tree_x,RandomEnemyTree[ii].tree_y,randomEnemyTreeArray[RandomEnemyTree[ii].treeIndex],255);
		}
	}
}

void setEnemyTrees(){

	for(ii=0;ii<TREESNUMBER;ii++)
	{
	if(RandomEnemyTree[ii].tree_x >= 540)RandomEnemyTree[ii].tree_x = 540;
	else RandomEnemyTree[ii].tree_x = 1280 ;
	RandomEnemyTree[ii].tree_y = 125 + rand()%300 ;
	RandomEnemyTree[ii].treeIndex = rand()%10;
	RandomEnemyTree[ii].treeShow = true;
	}
}

void collusion(){
	if(life<=5){
		iText(1100,100,"Main Menue: HOME");
		iText(100,100,"Quick Save: s");
		iText(100,690,"YOUR LIFE",GLUT_BITMAP_TIMES_ROMAN_24);
		for (ii=0;ii<TREESNUMBER;ii++){
	
			if(charX+100 >= RandomEnemyTree[ii].tree_x && charX+100 <= RandomEnemyTree[ii].tree_x +80 ){

				RandomEnemyTree[ii].tree_x = 1280;
				life ++;
				PlaySound("music\\jab.wav",NULL,SND_ASYNC);
			}

			for(int k = 0;k<=5;k++)
			   iShowBMP2(80,650,Life[life],0);
			RandomEnemyTree[ii].tree_y = 160;

			for(e2=0; e2<25; e2++){
			   if(sx[e2]>= RandomEnemyTree[ii].tree_x){
	
			RandomEnemyTree[ii].tree_x = 1700;
			RandomEnemyTree[ii].tree_y = 160;
			xxx++;
			printf("%d",xxx);
			PlaySound("music\\jab.wav",NULL,SND_ASYNC);
      		   }
			}
		}
	}

	if(life>=6){
		 iShowBMP(0,0,dead[0]);
	}
	
}