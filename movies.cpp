/*
  Getters, settes, and destructor for movies child class
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#include <iostream>
#include "movies.h"

using namespace std;

movies::movies(char* newTitle, int newYear, char* newDirector, int newDuration, int newRating):media(newTitle,newYear){
  title = newTitle;
  year = newYear;
  director = newDirector;
  duration = newDuration;
  rating = newRating;
  type = 1;
}

movies::~movies(){
  delete title;
  delete director;
}

char* movies::getDirector(){
  return director;
}

int movies::getDuration(){
  return duration;
}
int movies::getRating(){
  return rating;
}
int movies::getType(){
  return type;
}
