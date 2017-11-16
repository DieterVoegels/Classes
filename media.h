/*
  media parent class
  Author: Dieter Voegels
  Date: 11/15/2017
*/
#ifndef mediah
#define mediah
#include <iostream>

using namespace std;

class media{
 public:
  media(char*, int);
  char* getTitle();
  int getYear();
  virtual char* getPublisher();
  virtual int getRating();
  virtual char* getDirector();
  virtual int getDuration();
  virtual int getType();
  virtual char* getArtist();
 protected:
  char* title;
  int year;
  int type;
};
#endif
