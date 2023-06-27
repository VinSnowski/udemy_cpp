#include <iostream>

int main()
{
  const int dollar_value{100};
  const int quarter_value{25};
  const int dime_value{10};
  const int nickel_value{5};

  int dollars{0}, quarters{0}, dimes{0}, nickels{0}, pennies{0};
  int change{0};

  std::cin >> change;

  dollars = change / dollar_value;
  change %= dollar_value;
  quarters = change / quarter_value;
  change %= quarter_value;
  dimes = change / dime_value;
  change %= dime_value;
  nickels = change / nickel_value;
  change %= nickel_value;

  pennies = change;

  std::cout << "Dollars: " << dollars << std::endl;
  std::cout << "Quarters: " << quarters << std::endl;
  std::cout << "Dimes: " << dimes << std::endl;
  std::cout << "Nickels: " << nickels << std::endl;
  std::cout << "Pennies: " << pennies << std::endl;
}
