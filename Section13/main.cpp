// #include <iostream>
// #include <string>

// class Player
// {
// private:
//   std::string name;
//   int health;
//   int xp;

// public:
//   Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
//   int get_health() {return health;};
// };

// Player::Player(std::string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val}
// {
//   std::cout << "Three-args constructor" << this->health << std::endl;
// }

// int main()
// {
//   Player empty;
//   Player jonasbru{"Jonasbru",1};
//   Player kilkas{"Kilkas", 30};
//   Player ferros{jonasbru};
//   std::cout << ferros.get_health() << std::endl;

//   return 0;
// }

#include <iostream>

class Deep
{
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }

  Deep(int d);
  Deep(const Deep &source);
  ~Deep();
};

Deep::Deep(int d)
{
  data = new int;
  *data = d;
  std::cout << "Direct constructor";
}

Deep::Deep(const Deep &source) : Deep(*source.data)
{
  std::cout
      << "Deep copy constructor" << std::endl;
}

Deep::~Deep()
{
  delete data;
  std::cout << "Destructor freeing data" << std::endl;
}

void display_deep(Deep s)
{
  std::cout << s.get_data_value() << std::endl;
}

int main()
{
  Deep dp{1};
  display_deep(dp);
  display_deep(dp);
  display_deep(dp);
  Deep p{dp};
  p.set_data_value(100);
  display_deep(dp);
  display_deep(p);
  display_deep(p);
  display_deep(dp);

  return 0;
}