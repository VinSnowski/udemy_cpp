#include <iostream>

int main()
{

  int n1{7};
  int n2{9};
  std::cout << "7 / 9 = " << static_cast<double>(n1) / n2 << std::endl;
  std::cout << "7 / 9 = " << n1 / static_cast<double>(n2) << std::endl;
  return (0);
}
