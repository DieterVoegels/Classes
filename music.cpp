/*
  Getters, setters, and destructor for the music child class
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#include <iostream>
#include "music.h"

using namespace std;

music::music(char* newTitle, int newYear, char* newPublisher, char* newArtist, int newDuration):media(newTitle,newYear){
  title = newTitle;
  year = newYear;
  publisher = newPublisher;
  artist = newArtist;
  duration = newDuration;
  type = 2;
}

music::~music(){
  delete title;
  delete publisher;
  delete artist;
}

char* music::getPublisher(){
  return publisher;
}

int music::getDuration(){
  return duration;
}
char* music::getArtist(){
  return artist;
}
int music::getType(){
  return type;
}
