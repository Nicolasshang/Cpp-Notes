#include <cmath>
#include <iostream>

int AskForInteger() {
  int integer{};
  std::cin >> integer;
  return integer;  // In this case, the int "Integer" is the return value.
}

double PythagoreanTheorem(
    double x,
    double y) {  // Here, the compiler creates two new named "x" and "y", and
                 // copies the values of the corresponding arguments in the
                 // function call onto those variables.
  return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

void UnreferencedParameter(
    int count) {  // The "count" parameter used to have a
                  // use, but now it doesn't. If we removed the parameter, then
                  // the function would because because we are passing more
                  // values than it can accept.
}

void UnnamedParameter(
    int /* count */) {  // The sole parameter of this function is an unnamed
                        // parameter. These are useful whenever a parameter
                        // needs to exist, but is not used in the body of the
                        // function. The Google style guide recommends that you
                        // put a comment there to mark its previous name.
}

int main() {
  int x_side = {AskForInteger()};
  int y_side = {AskForInteger()};

  std::cout << PythagoreanTheorem(x_side, y_side) << "\n";

  UnreferencedParameter(4);  // Does not throw an error

  UnnamedParameter(4);  // Does not throw an error
}