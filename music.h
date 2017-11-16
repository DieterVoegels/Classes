/*
  music child class that contains all of the variables for music
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#include <iostream>
#include "media.h"

using namespace std;

class music:public media{
 public:
  music(char* newTitle, int newYear, char* newPublisher, char* newArtist, int newDuration);
  virtual char* getPublisher();
  virtual char* getArtist();
  virtual int getDuration();
  virtual int getType();
  ~music();
 private:
  char* publisher;
  int duration;
  char* artist;
};

