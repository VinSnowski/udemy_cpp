#include <iostream>
#include <string>

int main()
{

  std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  std::string input;
  std::string encrypted_input;
  std::string decrypted_input;
  std::getline(std::cin, input);

  size_t idx;

  for (auto c : input)
  {
    idx = alphabet.find(c);
    if (idx != std::string::npos)
    {
      encrypted_input += key.at(idx);
    }
    else
    {
      encrypted_input += c;
    }
  }
  std::cout << "Encrypted input: " << encrypted_input << std::endl;

  for (auto c : encrypted_input)
  {
    idx = key.find(c);
    if (idx != std::string::npos)
    {
      decrypted_input += alphabet.at(idx);
    }
    else
    {
      decrypted_input += c;
    }
  }

  std::cout << "Decrypted (original) input: " << decrypted_input << std::endl;
  std::cout << std::endl;

  return 0;
}
