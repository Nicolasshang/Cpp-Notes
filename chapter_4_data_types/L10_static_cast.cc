#include <cstdint>
#include <iostream>

// * ===== type conversion ===== *

// When the compiler converts a type for us, that is called implicit type
// conversion.

// Type conversion in C++ produces a new value, e.g. when an int variable is
// passed to a double parameter, a new double value is created and given the
// value of the int.

// * ===== type conversion warnings ===== *

// When we try to convert a larger integral to a smaller integral type (e.g.
// double to int), the compiler usually generates a warning about loss of data.

// This is one of the reasons brace initialization is preferred: It always
// throws an error when we try to initialize with something that will lose value
// once converted.

// * ===== static_cast ===== *

// We can explicitly convert types explicitly using the
// static_cast<new_type>(expression) operator.

// Note: When you see angled brackets in C++, the parameter is usually a type.

long long Factorial(int x) {
  int current_number{x};
  long long total{x};

  while (current_number > 1) {
    total *= current_number - 1;
    current_number--;
  }

  return total;
}

void FactorialTest() {
  double temp_double{15.9};
  std::cout << Factorial(static_cast<int>(temp_double)) << '\n';
}

// * ===== converting unsigned to signed ===== *

// You can also use the operator to convert unsigned ints to signed ints.

void UnsignedToSigned() {
  unsigned int unsigned_number{};
  int signed_number{static_cast<int>(unsigned_number)};
  std::cout << signed_number << '\n';
}

// * ===== int8_t and its problems ===== *

// int8_t and uint8_t can behave like characters. For example:

void Int8_tProblems() {
  std::int8_t temp_int8{65};
  std::cout
      << temp_int8
      << '\n';  // Outputs A because 65 is the code point of that char in ASCII.
}

int main() {
  FactorialTest();
  UnsignedToSigned();
  Int8_tProblems();
}
