// * ===== Tactic 1: conditionalizing the debug statements ====== *

// Since debug statements clutter up your code, you can use preprocessor macros
// to filter them out whenever you don't want them. For example:

#include <iostream>

#define ENABLE_DEBUGGING  // Comment out when you're done with debugging

int GetUserInput() {
#ifdef ENABLE_DEBUGGING
  std::cerr << "GetUserInput() called" << "\n";
#endif
  std::cout << "Enter a number: " << "\n";
  int input{};
  std::cin >> input;
  return input;
}

int main() {
#ifdef ENABLE_DEBUGGING
  std::cerr << "main() called" << "\n";
#endif
  int user_input{GetUserInput()};
  std::cout << user_input << "\n";
}

// * ===== Tactic 2: using a logger ===== *

// A log is a sequential record of the events that happened in the program. Logs
// are generally written on a file in the disk called a "log file."

// C++ contains an output stream called std::clog, but it writes to the same
// stream as std::cerr which makes it more cumbersome. Here, it is likely more
// efficient to use some third-party logging library like plog or spdlog.