// * ===== Tactic 1: comment out the code ===== *

// This is self-explanatory. Commenting out the code rules out certain
// statements as the culprit.

// An alternative to commenting/uncommenting out code is to use a third-party
// library that will let you leave debug statements in the code but compile them
// out in release mode via a preprocessor macro. dbg is one such library.

// Note: "release mode" and "debug mode" are both modes the compiler can be in.
// In the former, variables can be optimized out and some source code statements
// can be removed or rearranged. In the latter, that doesn't happen so it's
// easier for debugging.

// * ===== Tactic 2: validating the code flow ===== *

// Another common issue is when programs call a function too many (or too few)
// times. To keep track of them, it can be helpful to print a function's name
// whenever it is called.

// Note: since std::cout is buffered, which means the program can crash before
// it had a chance to be flushed to the console. The better alternative
// is to use std::cerr, which is unbuffered. For example:

#include <iostream>

int ReturnFive() {
  std::cerr << "ReturnFive() called" << "\n";
  return 5;
}

void ReturnFiveDebug() {
  for (int i = 0; i < 10; i++) {
    ReturnFive();
  }
}

// Note: You can achieve the same effect by calling setbuf(stdout, NULL) which
// disables buffering on stdout altogether, or by calling fflush(stdout)
// whenever you want to flush it. Lastly, calling std::cout << std::unitbuf also
// works.

// * ===== Tactic 3: printing values ===== *

// Printing variables also helps. For example:

#include <cmath>

double PythagoreanTheorem(double width, double height) {
  std::cerr << "width: " << width << " height: " << height << "\n";
  return std::sqrt(width * width + height * height);
}

void PythagoreamTheoremDebug() {
  for (int i = 0; i < 10; i++) {
    PythagoreanTheorem(i, i);
  }
}

// However, adding debug statements isn't great in general because it clutters
// up the code, isn't reusable, and can introduce more bugs.

int main() {
  ReturnFiveDebug();
  PythagoreamTheoremDebug();
}