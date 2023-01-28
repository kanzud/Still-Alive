char pc[10][30]={"pc\\3.bmp","pc\\1.bmp","pc\\2.bmp","pc\\rules.bmp","pc\\5.bmp"};
char s1[11][30]={"story1\\s1.bmp","story1\\s2.bmp","story1\\s3.bmp","story1\\s4.bmp","story1\\s5.bmp","story1\\s6.bmp","story1\\s7.bmp","story1\\s8.bmp"};
char loading[1][20]={"pc\\l.bmp"};
char c1[3][20]={"credit\\c1.bmp","credit\\c2.bmp","credit\\c3.bmp"};
char button[10][30]={"button\\1.bmp","button\\2.bmp","button\\3.bmp","button\\4.bmp","button\\5.bmp","button\\6.bmp"};
char lol[10][30]={"loading\\1.bmp","loading\\2.bmp","loading\\3.bmp","loading\\4.bmp","loading\\5.bmp","loading\\6.bmp","loading\\7.bmp","loading\\8.bmp"};
void picture();
void story();
void Credit();
void Button();
int kal=-1;
int kla=0;


int b=0,c=0,d=0,e=0,f=0;

void picture(int index)
{
	if(index != 5){

	iShowBMP(0,0,pc[index]);
	}


}

void testLoad(int i){
	if(i==-1){
		kal = -1;
		if(kal == 0)iShowBMP(0,0,lol[0]);
		if(kal == 1)iShowBMP(0,0,lol[1]);
		if(kal == 2)iShowBMP(0,0,lol[2]);
		if(kal == 3)iShowBMP(0,0,lol[3]);
		if(kal == 4)iShowBMP(0,0,lol[4]);
		if(kal == 5)iShowBMP(0,0,lol[5]);
		if(kal == 6)iShowBMP(0,0,lol[6]);
		if(kal == 7)iShowBMP(0,0,lol[7]);
	}



}

void time1(){
	
	if(kal=-1){
		kla++;
	}

}
void story(int i,int x)
{

		if(x==1){
			if(i==-1) iShowBMP(0,0,loading[0]);
			if(i==0) iShowBMP(0,0,s1[0]);
			if(i==1) iShowBMP(0,0,s1[1]);
			if(i==2) iShowBMP(0,0,s1[2]);
			if(i==3) iShowBMP(0,0,s1[3]);            
			if(i==4) iShowBMP(0,0,s1[4]);                       /////////telling story//////
			if(i==5) iShowBMP(0,0,s1[5]);
			if(i==6) iShowBMP(0,0,s1[6]);
			if(i==7) iShowBMP(0,0,s1[7]);
		}
}

void Credit(int i){

		if(i== -1){
			iShowBMP(0,0,loading[0]) ;
		}
		if(i == 0)
			//printf("%d",i);
			iShowBMP(0,0,c1[0]) ;
		if(i == 1)
			//printf("%d",i);
			 iShowBMP(0,0,c1[1]);
		if(i == 2) 
			//printf("%d",i);
			iShowBMP(0,0,c1[2]);
		

}
void Button(){

	 if(b==0)iShowBMP2(65,470,button[b],0);
	 if(b==5)iShowBMP2(65,470,button[b],0);
	 if(b==0){
		 iSetColor(255,191,0);
	   iText(123,518,"START",GLUT_BITMAP_TIMES_ROMAN_24);
	 } 
	 if(b==5){
		 iSetColor(0,0,0);
	   iText(123,518,"START",GLUT_BITMAP_TIMES_ROMAN_24);
	 }

	 if(c==0)iShowBMP2(65,370,button[c],0);
	 if(c==5)iShowBMP2(65,370,button[c],0);
	 if(c==0){
		 iSetColor(255,191,0);
	   iText(104,418,"CONTROL",GLUT_BITMAP_TIMES_ROMAN_24);
	 } 
	 if(c==5){
		 iSetColor(0,0,0);
	   iText(104,418,"CONTROL",GLUT_BITMAP_TIMES_ROMAN_24);
	 }

	 if(d==0)iShowBMP2(65,270,button[d],0);
	 if(d==5)iShowBMP2(65,270,button[d],0);
	 if(d==0){
		 iSetColor(255,191,0);
	   iText(114,318,"RECORD",GLUT_BITMAP_TIMES_ROMAN_24);
	 } 
	 if(d==5){
		 iSetColor(0,0,0);
	   iText(114,318,"RECORD",GLUT_BITMAP_TIMES_ROMAN_24);
	 }

	 if(e==0)iShowBMP2(65,170,button[e],0);
	 if(e==5)iShowBMP2(65,170,button[e],0);
	 if(e==0){
		 iSetColor(255,191,0);
	   iText(112,218,"CREDITS",GLUT_BITMAP_TIMES_ROMAN_24);
	 } 
	 if(e==5){
		 iSetColor(0,0,0);
	   iText(112,218,"CREDITS",GLUT_BITMAP_TIMES_ROMAN_24);
	 }

	 if(f==0)iShowBMP2(65,70,button[f],0);
	 if(f==5)iShowBMP2(65,70,button[f],0);
	 if(f==0){
		 iSetColor(255,191,0);
	   iText(133,118,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	 } 
	 if(f==5){
		 iSetColor(0,0,0);
	   iText(133,118,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	 }
	 
}