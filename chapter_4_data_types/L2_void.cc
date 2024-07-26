// * ====== the void type ====== *

// The void type is an incomplete type, meaning that it has been declared but
// not defined. The compiler knows about the existence of such types, but doesnt
// know how much memory to allocate to them.

// Therefore, instantiations like void a; wont work.

#include <iostream>

// * ===== using void to indicate an empty parameter list ====== *

// Void can also be used to define a function with no parameters. The only
// reason this function below compiles is because of backwards compatibility
// reasons, so this isn't good practice.

int GetValue(void) {
  int x{};
  std::cin >> x;

  return x;
}

int main() { std::cout << GetValue() << "\n"; }