#include"Audio.h"
#include <iostream>

Audio::Audio()
{	
	this->maybeNextTimeBuffer.loadFromFile("E:\\PenguinRunner\\SFML\\audio\\maybe-next-time.wav");
	this->backroundSongBuffer.loadFromFile("E:\\PenguinRunner\\SFML\\audio\\Inner Circle- Bad Boys.wav");
}
void Audio::playMaybeNextTime()
{
	this->maybeNextTime.setBuffer(this->maybeNextTimeBuffer);
	this->maybeNextTime.setVolume(70.0f);
	this->maybeNextTime.play();
}
void Audio::playFundalSong()
{
	this->backroundSong.setBuffer(this->backroundSongBuffer);
	this->backroundSong.setVolume(30);
	this->backroundSong.play();

}