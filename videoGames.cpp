/*
  video game's getters, setters, and destructor
  Author: Dieter Voegels
  Date: 11/15/20117
*/
#include <iostream>
#include "videoGames.h"

using namespace std;

videoGames::videoGames(char* newTitle, int newYear, char* newPublisher, int newRating):media(newTitle,newYear){
  title = newTitle;
  year = newYear;
  publisher = newPublisher;
  rating = newRating;
  type = 0;
}

videoGames::~videoGames(){
  delete title;
  delete publisher;
}

char* videoGames::getPublisher(){
  return publisher;
}

int videoGames::getRating(){
  return rating;
}
int videoGames::getType(){
  return type;
}
