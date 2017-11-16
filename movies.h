/*
  movies child class contain all of the variables for movies
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#include <iostream>
#include "media.h"

using namespace std;

class movies:public media{
 public:
  movies(char*, int, char*, int, int);
  virtual char* getDirector();
  virtual int getDuration();
  virtual int getRating();
  virtual int getType();
  ~movies();
 private:
  char* director;
  int duration;
  int rating;
};
