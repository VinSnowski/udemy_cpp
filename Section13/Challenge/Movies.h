// Here is what your project files should look like:
// -Movie.h - include file with the Movie class specification
// -Movie.cpp -  file with the Movie class implementation
// -Movies.h - include file with the Movies class specification
// -Movies.cpp -  file with the Movies class implementation
// -main.cpp - the main driver that creates a Movies object and adds and increments movies

// class Movie - models a movie which includes
// - movie name
// - movie rating (G, PG, PG-13, R)
// - watched - the number of times the movie has been watched

#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>
#include "Movie.h"

class Movies
{
private:
  std::vector<Movie> movie_list;

public:
  Movies();
  ~Movies();
  Movies(const Movies &source);
  Movies(Movies &&source);
  bool add_movie(std::string name, std::string rating, int watched_count);
  bool increment_watch_count(std::string name, int value = 1);
  void display_all();
};

#endif // _MOVIES_H_