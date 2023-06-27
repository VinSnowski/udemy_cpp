#include <iostream>
#include <vector>
#include <climits>

void display_menu()
{
  std::cout << "P - Print numbers" << std::endl;
  std::cout << "A - Add a number" << std::endl;
  std::cout << "M - Display mean of the numbers" << std::endl;
  std::cout << "S - Display the smallest number" << std::endl;
  std::cout << "L - Display the largest number" << std::endl;
  std::cout << "Q - Quit" << std::endl;
}

void handle_display();


int main()
{

  char choice{};
  int input{};
  std::vector<int> vec;

  do
  {

    std::cin >> choice;
    std::cout << std::endl;

    switch (choice)
    {
    case 'p':
    case 'P':
      if (vec.size() == 0)
      {
        std::cout << "[] - the list is empty" << std::endl;
      }
      else
      {
        std::cout << "[ ";
        for (auto v : vec)
        {
          std::cout << v << " ";
        }
        std::cout << " ]" << std::endl;
      }
      break;

    case 'a':
    case 'A':
      std::cout << "Type an integer to add to the list: ";
      std::cin >> input;
      vec.push_back(input);
      std::cout << std::endl;
      std::cout << input << " added" << std::endl;
      break;

    case 'm':
    case 'M':
      if (vec.size() > 0)
      {
        double mean{0};
        for (auto v : vec)
        {
          mean += v;
        }
        mean = mean / vec.size();
        std::cout << "Mean is " << mean << std::endl;
      }
      else
      {
        std::cout << "Unable to calculate the mean - no data" << std::endl;
      }
      break;

    case 's':
    case 'S':
      if (vec.size() > 0)
      {
        int smallest{INT_MAX};
        for (auto v : vec)
        {
          if (v < smallest)
          {
            smallest = v;
          }
        }
        std::cout << "Smallest element is " << smallest << std::endl;
      }
      else
      {
        std::cout << "Unable to perform operation - no data" << std::endl;
      }
      break;

    case 'l':
    case 'L':
      if (vec.size() > 0)
      {
        int biggest{INT_MIN};
        for (auto v : vec)
        {
          if (v > biggest)
          {
            biggest = v;
          }
        }
        std::cout << "Biggest element is " << biggest << std::endl;
      }
      else
      {
        std::cout << "Unable to perform operation - no data" << std::endl;
      }
      break;

    case 'q':
    case 'Q':
      break;

    default:
      std::cout << "Unknown selection, please try again" << std::endl;
    }
    std::cout << std::endl;
  } while (choice != 'Q' && choice != 'q');

  std::cout << "Goodbye!" << std::endl;
}