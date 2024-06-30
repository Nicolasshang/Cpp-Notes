#include <iostream>

int add(int x, int y) {  // The "lifetime" of a local variable is the duration
                         // between when it is created and destroyed. The
                         // lifetime of x and y start here.
  return x + y;
}  // The lifetimes end here. Now, the two variables are invalidated and any
   // further attempts to use them will result in undefined behavior.

int main() {
  int x{5};
  int y{6};  // Local variables in main's scope

  std::cout << "Enter a number: " << "\n";
  int z{};  // A variable should be defined as closely to their first use as
            // reasonable
  std::cin >> z;

  std::cout << add(x, y)
            << "\n";  // Here, the compiler creates a "temporary
                      // object" to store the optput of add(x, y). Temporary are
                      // destroyed at the end of the expression they reside in.
                      // They also have no scope, as scope can only come with an
                      // identifier, which they don't have.
}