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

#include <iostream>
#include <string>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watched) : name(name), rating(rating), watched(watched)
{
}

Movie::Movie(const Movie &source) : Movie{source.name, source.rating, source.watched}
{
}

Movie::Movie(Movie &&source) : Movie{source.name, source.rating, source.watched}
{
  std::cout << "Move constructor was called for " << source.name << std::endl;
}

Movie::~Movie()
{
}

std::string Movie::get_name() const
{
  return name;
}

std::string Movie::get_rating() const
{
  return rating;
}

int Movie::get_watched() const
{
  return watched;
}

void Movie::increment_watch_count()
{
  watched++;
}

void Movie::display() const
{
  std::cout << "Name: " << name << std::endl;
  std::cout << "Rating: " << rating << std::endl;
  std::cout << "Times watched: " << watched << std::endl;
}