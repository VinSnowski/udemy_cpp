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

#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
  //  friend class Movies;

private:
  std::string name;
  std::string rating;
  int watched;

public:
  Movie(std::string name, std::string rating, int watched);
  Movie(const Movie &source);
  Movie(Movie &&source);
  ~Movie();
  std::string get_name() const;
  std::string get_rating() const;
  int get_watched() const;
  void increment_watch_count();
  void display() const;
};

#endif // _MOVIE_H_