#include <iostream>

// * ====== integer integral types ====== *

// An integer is an integral type that can hold both positive and negative
// numbers. There are four integer types that C++ provides:

// ! list of all integer types

// short int (minimum size: 16 bits)
// int (minimum size: 16 bits)
// long int (minimum size: 32 bits)
// long long int (minimum size: 64 bits)

// * ====== signed integers ===== *

// The attribute of being positive, negative, or zero is called a number's sign.

// By default, integers in C++ are signed, meaning that they can store both
// positive and negative numbers (and 0).

// In binary representation, a single bit (called the sign bit) is used to store
// the sign of the number. All of ther other bits are called the magnitude bits,
// and are used to store the value of the number.

// * ===== defining signed integers ===== *

// The best practice of naming signed ints goes like this:

void BestPractice() {
  short a{};
  int b{};
  long c{};
  long long d{};
}

// You can also add the int suffix or the signed prefix, but doing that is not
// best practice because integer types are signed by default.

void NotBestPractice() {
  signed short int a{};
  signed int b{};
  signed long int c{};
  signed long long int d{};
}

// * ===== overflow ===== *

// When a number is assigned a value that is higher than or lower than its
// maximum/minimum value, it results in undefined behaviour. This phenomena is
// known as overflow. For example:

void Overflow() {
  int number{INT_MAX};  // The maximum value of a 4-byte signed integer
  std::cout << number << "\n";

  number++;  // Overflow occurs; undefined behaviour from here on out.
  std::cout << number << "\n";

  int number_2{INT_MIN};  // The minimum size of an int
  std::cout << number_2 << "\n";

  number_2--;  // Overflow occurs again.
  std::cout << number_2 << "\n";
}

// * ===== integer division ===== *

// When dividing with two integers, C++ always produces an integer result and
// the fractional component is dropped. There is no rounding. For example,

void IntegerDivision() {
  std::cout << 8 / 5 << "\n";  // Returns 1
}

// When fractional answers are desierd, C++ provides some arithmetic utilities.

int main() {
  Overflow();
  IntegerDivision();
}