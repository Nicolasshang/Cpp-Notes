#include <iostream>

// The first line of the function is the function header
int Five() {
  // The inner part of the function is called the function body
  return 5;
}

int main() {
  // A typical function call. A lesser-known name of the function being called
  // is "callee"
  std::cout << Five() << "\n";
}