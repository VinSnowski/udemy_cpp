#include <iostream>

enum RobotState
{
  Idle,
  Walking,
  Operating
};

std::istream &operator>>(std::istream &is, RobotState &rs)
{
  std::underlying_type_t<RobotState> user_input;
  is >> user_input;
  switch (user_input)
  {
  case Idle:
    rs = RobotState(user_input);
    break;
  case Walking:
    rs = RobotState(user_input);
    break;
  case Operating:
    rs = RobotState(user_input);
    break;

  default:
    std::cout << "Input is not a valid state" << std::endl;
    break;
  }
  return is;
}

int main()
{
  RobotState new_state;
  std::cout << "Please update the robot state: ";
  std::cin >> new_state;
  std::cout << "Informed current state is: " << new_state << std::endl;
}