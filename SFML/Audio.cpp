#include"Audio.h"
#include <iostream>

Audio::Audio()
{	
	this->maybeNextTimeBuffer.loadFromFile("audio\\maybe-next-time.wav");
	this->backroundSongBuffer.loadFromFile("audio\\Inner Circle- Bad Boys.wav");
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