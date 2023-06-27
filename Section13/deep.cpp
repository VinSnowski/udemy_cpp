// #include <iostream>

// class Deep
// {
// private:
//   int *data;

// public:
//   void set_data_value(int d) { *data = d; }
//   int get_data_value() { return *data; }

//   Deep(int d);
//   Deep(const Deep &source);
//   ~Deep();
// };

// Deep::Deep(int d)
// {
//   data = new int;
//   *data = d;
// }

// Deep::Deep(const Deep &source) : Deep(*source.data)
// {
//   std::cout
//       << "Deep copy constructor" << std::endl;
// }

// Deep::~Deep()
// {
//   delete data;
//   std::cout << "Destructor freeing data" << std::endl;
// }

// void display_deep(Deep s)
// {
//   std::cout << s.get_data_value() << std::endl;
// }

// int main()
// {
//   Deep dp{1};
//   display_deep(dp);
//   display_deep(dp);
//   display_deep(dp);
//   Deep p{dp};
//   display_deep(dp);
//   display_deep(p);
//   display_deep(p);
//   display_deep(dp);

//   return 0;
// }