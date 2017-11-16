/*
  video game child class that contains variables for video games
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#include <iostream>
#include "media.h"

using namespace std;

class videoGames:public media{
 public:
  videoGames(char* newTitle, int newYear, char* newPublisher, int newRating);
  virtual char* getPublisher();
  virtual int getRating();
  virtual int getType();
  ~videoGames();
 private:
  char* publisher;
  int rating;
};
