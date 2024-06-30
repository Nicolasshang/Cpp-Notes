#include <iostream>

void ReturnNothing() {}

int ReturnFive() { return 5; }

int main() {
  ReturnFive();
  ReturnNothing();  // Both of these functions will compile, but only
                    // ReturnFive() will do something significant.
}