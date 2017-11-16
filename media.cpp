/*
  media's parent cpp file that transforms into a video game, music, or movie. has getters for every child and setters for title and year
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#include <iostream>
#include "media.h"

using namespace std;

media::media(char* newTitle, int newYear){
  title = newTitle;
  year = newYear;
}

char*  media::getTitle(){
  return title;
}

int media::getYear(){
  return year;
}
char* media::getPublisher(){
  return NULL;
}
int  media::getRating(){
  return NULL;
}
char* media::getDirector(){
  return NULL;
}
int media::getDuration(){
  return NULL;
}
int media::getType(){
  return NULL;
}
char* media::getArtist(){
  return NULL;
}
