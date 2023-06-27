#include <iostream>

int main()
{

  double cost_small_room{25.0};
  double cost_large_room{35.0};
  double sales_tax_rate{0.06};

  double cost{0};
  double tax{0};

  int estimation_valid_days{30};

  int n_small{0};
  int n_large{0};

  std::cout << "Number of small rooms: ";
  std::cin >> n_small;

  std::cout << "Number of large rooms: ";
  std::cin >> n_large;

  std::cout << "Price per small room: $" << cost_small_room << std::endl;
  std::cout << "Price per large room: $" << cost_large_room << std::endl;

  cost = n_small * cost_small_room + n_large * cost_large_room;
  tax = sales_tax_rate * cost;

  std::cout << "Cost: $" << cost << std::endl;
  std::cout << "Tax: $" << tax << std::endl;
  std::cout << "===========================" << std::endl;
  std::cout << "Total estimate: $" << (cost + tax) << std::endl;
  std::cout << "This estimate is valid for " << estimation_valid_days << " days" << std::endl;

  return (0);
}
