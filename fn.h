
int l;

void load(){
	l+=100;
}


void Load(){
	 iSetColor(0,225,0);
	   iText(270,135,"Loading.......",GLUT_BITMAP_HELVETICA_18);
	   iRectangle(270,100,700,25);

	     if(l==100){
			 iFilledRectangle(270,100,l+100,25); 
			// return l;
		 }                                                                      ///////loading page///////
		 else if(l==200){
			 iFilledRectangle(270,100,l,25);
			// return l;
		 }
		 else if(l==300){
			 iFilledRectangle(270,100,l,25);
			 //return l;
		 }
		 else if(l==400){ 
			 iFilledRectangle(270,100,l,25);
			// return l;
		 }
		 else if(l==500){
			 iFilledRectangle(270,100,l,25);
			// return l;
		 }
		 else if(l==600){
			 iFilledRectangle(270,100,l,25);
			 //return l;
		 }
		 else if(l==700){ 
			 iFilledRectangle(270,100,l,25);
			// return l;
		 }
		 else if (l==800) {
			// return l;
		 }
}


