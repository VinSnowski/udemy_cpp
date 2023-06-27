
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "Movies.h"

bool Movies::add_movie(std::string name, std::string rating, int watched_count)
{
  for (const Movie &m : movie_list)
  {
    if (m.get_name() == name)
      return false;
  }
  movie_list.push_back(Movie{name, rating, watched_count});
  return true;
}
void Movies::display_all()
{
  for (const Movie m : movie_list)
  {
    m.display();
    std::cout << "    ------    " << std::endl;
  }
  std::cout << std::endl;
}

bool Movies::increment_watch_count(std::string name, int value)
{
  for (Movie &m : movie_list)
  {
    if (m.get_name() == name)
    {
      m.increment_watch_count();
      return true;
    }
  }
  std::cout << "Error: This movie does not exist in the list" << std::endl;
  return false;
}

Movies::Movies()
{
}

Movies::~Movies()
{
}

Movies::Movies(const Movies &source)
{
}

Movies::Movies(Movies &&source)
{
}
