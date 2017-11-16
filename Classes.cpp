/*
  This code is a database for movies, video games, and music. You can add, search, and delete these medias.
  Author: Dieter Voegels
  Date: 11/15/2017
*/
//include libraries and classes
#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "videoGames.h"
#include "movies.h"
#include "music.h"

using namespace std;

//function prototypes
void Add(vector<media*> &vect, char newTitle[], int newYear, char newPublisher[], int newRating, char newDirector[], int newDuration, char newArtist[]);
void titleSearch(vector<media*> &vect);
void yearSearch(vector<media*> &vect);
void Delete(vector<media*> &vect);

//contstructor
int main(){
  //initialize variables and vector
  bool quit = false;
  char input[10];
  vector<media*> vect;
  cout << "Welcome to the media database." << endl;
  //main while loop
  while(quit == false){
    //user instructions
    cout << "Type in a command. Type 'help' for the commands. This program is case sensitve" << endl;
    cin.getline(input, 10);

    //if user types in add, then run the add function
    if(strcmp(input, "add") == 0){
      //initialize variables
      char* newTitle = new char[100];
      int newYear;
      char* newPublisher = new char[80]; 
      int newRating;
      char* newDirector = new char[100];
      int newDuration;
      char* newArtist = new char[100];
      //run add funciton and pass in variables
      Add(vect, newTitle, newYear, newPublisher, newRating, newDirector, newDuration, newArtist);
    }
    //if the user types in search, then run the search funtion
    if(strcmp(input, "search") == 0){
      cout << "Would you like to search by title or year?" << endl;
      cout << "Type title or year to choose how you want to search for the media" << endl;
      char searchInput[10];
      cin.getline(searchInput, 10);
      //run the title search funtion if they type in title
      if(strcmp(searchInput, "title") == 0){
	titleSearch(vect);
      }
      //run the year search funtion if they type in year
      else if(strcmp(searchInput, "year") == 0){
	yearSearch(vect);
      }
    }
    //if the user types in delte, run the delte funtion
    if(strcmp(input, "delete") == 0){
      Delete(vect);
    }
    //if the user types in help, print out all of the commands
    if(strcmp(input, "help") == 0){
      cout << "Type 'add' to add a media to the data base" << endl;
      cout << "Type 'search' to search the data base" << endl;
      cout << "Type 'delete' to delete a media" << endl;
      cout << "Type 'quit' to quit the program" << endl;
      cout << "Type 'help' to print help commands" << endl;
    }
    //if user types in quit, then kill the program
    if(strcmp(input, "quit") == 0){
      quit = true;
    }
  }
}

//add function
void Add(vector<media*> &vect, char newTitle[], int newYear, char newPublisher[], int newRating, char newDirector[], int newDuration, char newArtist[]){
  //get the title
  cout << "What is the title of the media?" << endl;
  cin.getline(newTitle, 100);

  //get the year
  cout << "What is the year of the media?" << endl;
  cin >> newYear;
  cin.ignore();

  //get the type of media
  cout << "Is the media music, movie, or video game?" << endl;
  char type[20];
  cin.getline(type, 20);

  //if its music get music data
  if(strcmp(type, "music") == 0){
    //get artist
    cout << "What is the artist of the music?" << endl;
    cin.getline(newArtist, 100);
    //get duration
    cout << "What is the duration of the music in minutes" << endl;
    cin >> newDuration;
    cin.ignore();
    //get publisher
    cout << "what is the Publisher of the music?" << endl;
    cin.getline(newPublisher, 100);
    //create the music child and add it to the vector
    music* musicPointer = new music(newTitle, newYear, newPublisher, newArtist, newDuration);
    vect.push_back(musicPointer);
    cout << "The music has been added" << endl;
  }
  //if its a movie get movie data
  if(strcmp(type, "movie") == 0){
    //get director
    cout << "What is the director of the movie?" << endl;
    cin.getline(newDirector, 100);
    //get duration
    cout << "What is the duration of the movie in minutes?" << endl;
    cin >> newDuration;
    cin.ignore();
    //get rating
    cout << "What is the rating of the movie?" << endl;
    cin >> newRating;
    cin.ignore();
    //create movie child and add it to the vector
    movies* moviesPointer = new movies(newTitle, newYear, newDirector, newDuration, newRating);
    vect.push_back(moviesPointer);
    cout << "The movie has been added" << endl;
  }
  //if its a video game get video game data
  if(strcmp(type, "video game") == 0){
    //get rating
    cout << "What is the rating of the video game?" << endl;
    cin >> newRating;
    cin.ignore();
    //get publisher
    cout << "What is the publisher of the video game?" << endl;
    cin.getline(newPublisher,80);
    //create videoGames child and add it to the vector
    videoGames* videoGamesPointer = new videoGames(newTitle, newYear, newPublisher, newRating);
    vect.push_back(videoGamesPointer);
    cout << "The video game has been added" << endl;
  }
}

//search by title function
void titleSearch(vector<media*> &vect){
  //get the title of the media
  cout << "Type in the title of the media" << endl;
  char input[100];
  cin.getline(input, 100);
  //for loop to run through all of the classes in the vector
  for(vector<media*>::iterator it = vect.begin(); it != vect.end(); it++){
    //if it matches then find out which media it is then print out the media's information
    if(strcmp((*it)->getTitle(),input) == 0){
      if((*it)->getType() == 0){
	cout << "Title:" << (*it)->getTitle() << endl;
	cout << "Year:" << (*it)->getYear() << endl;
	cout << "Publisher:" << (*it)->getPublisher() << endl;
	cout << "Rating:" << (*it)->getRating() << endl;
      }
      if((*it)->getType() == 1){
	cout << "Title:" << (*it)->getTitle() << endl;
	cout << "Year:" << (*it)->getYear() << endl;
	cout << "Director:" << (*it)->getDirector() << endl;
	cout << "Duration:" << (*it)->getDuration()<< endl;
	cout << "Rating:" << (*it)->getRating() << endl;
      }
      if((*it)->getType() == 2){
	cout << "Title:" << (*it)->getTitle() << endl;
	cout << "Year:" << (*it)->getYear() << endl;
	cout << "Publisher:" << (*it)->getPublisher() << endl;
	cout << "Artist:" << (*it)->getArtist()<< endl;
	cout << "Duration:" << (*it)->getDuration() << endl;
      }
    }
  }
}

//search by year function
void yearSearch(vector<media*> &vect){
  //get the year of the media
  cout << "Type in the year of the media" << endl;
  int input;
  cin >> input;
  cin.ignore();
  //for loop to run through all of the classes in the vector
  for(vector<media*>::iterator it = vect.begin(); it != vect.end(); it++){
    //if the year matches the year of a class then get the type of media and print out it's information
    if((*it)->getYear() == input){
      if((*it)->getType() == 0){
	cout << "Title:" << (*it)->getTitle() << endl;
	cout << "Year:" << (*it)->getYear() << endl;
	cout << "Publisher:" << (*it)->getPublisher() << endl;
	cout << "Rating:" << (*it)->getRating() << endl;
      }
      if((*it)->getType() == 1){
	cout << "Title:" << (*it)->getTitle() << endl;
	cout << "Year:" << (*it)->getYear() << endl;
	cout << "Director:" << (*it)->getDirector() << endl;
	cout << "Duration:" << (*it)->getDuration()<< endl;
	cout << "Rating:" << (*it)->getRating() << endl;
      }
      if((*it)->getType() == 2){
	cout << "Title:" << (*it)->getTitle() << endl;
	cout << "Year:" << (*it)->getYear() << endl;
	cout << "Publisher:" << (*it)->getPublisher() << endl;
	cout << "Artist:" << (*it)->getArtist()<< endl;
	cout << "Duration:" << (*it)->getDuration() << endl;
      }
    }
  }
}

//delete function
void Delete(vector<media*> &vect){
  //get the title of the media
  cout << "Type in the title of the media" << endl;
  char input[100];
  cin.getline(input, 100);
  //for loop to run through all of the classes in the vector
  for(vector<media*>::iterator it = vect.begin(); it !=vect.end(); it++){
    //postion in the vector
    int position = it - vect.begin();
    //if the title matches the title of the media, then delete that media
    if(strcmp((*it)->getTitle(),input) == 0){
      if((*it)->getType() == 0){
	delete static_cast<videoGames*>(*it);
	vect.erase(vect.begin() + position);
	cout << "Media has been deleted" << endl;
	break;
      }
      if((*it)->getType() == 1){
	delete static_cast<movies*>(*it);
	vect.erase(vect.begin() + position);
	cout << "Media has been deleted" << endl;
	break;
      }
      if((*it)->getType() == 2){
	delete static_cast<music*>(*it);
	vect.erase(vect.begin() + position);
	cout << "Media has been deleted" << endl;
	break;
      }
    }
  }
}
