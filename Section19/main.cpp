#include <iostream>
#include <fstream>

int main()
{
  std::fstream ifile; //{"file1", std::ios::in};
  ifile.open("Section19/file1");

  std::cout << ifile.is_open() << std::endl;
  int c;
  ifile >> c;
  std::cout << c;

  ifile.close();
}