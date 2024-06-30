#include <iostream>

int GetNumberFromUser() {
  int number{};
  std::cout << "Input a number: " << "\n";
  std::cin >> number;
  return number;  // Once return is called, then the value is copied and and
                  // function exits immediately. Then, the value is passed to
                  // the function caller. This process is called "return by
                  // value."
}

int main() {
  int value_from_user = GetNumberFromUser();
  std::cout << value_from_user << "\n";
  std::cout << GetNumberFromUser << "\n";  // This will technically compile, but
                                           // results in undefined behaviour.

  return 0;  // The reason main functions return 0 because it is the status
             // (exit) code for when the program runs sucessfully. Functions
             // will implicitly return 0 if no exit code is provided.
}