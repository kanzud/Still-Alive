void Sound();

void Sound(int index){
	if(index == 0)
		PlaySound("music\\1.wav",NULL, SND_LOOP | SND_ASYNC);
}