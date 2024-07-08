#include <iostream>

int main() {
  int a;      // no initializer (default)
  int b = 4;  // initial value after equals sign (copy initialization)
  int c(6);   // initial value in parenthesis (direct initialization)

  // List initialization methods (recommended)
  int d{7};     // initial value in braces (direct list initialization)
  int e = {8};  // initial value in braces after equals sign (copy list
                // initialization)
  int f{};      // initial value is in empty brances (value initialization)
}