#include <iostream>

// * ===== octal ===== *

// Octal is a numbering system that only uses eight unique symbols. As a result,
// it skips from 7 to 10.

// the '0' prefix identifies the following number as an octal number

void OctalDemonstration() {
  int octal_number = 012;
  std::cout << octal_number << '\n';  // Should print 10
}

// * ===== hexadecimal ===== *

// Hexadecimal is the numbering system in base 16 (i.e. 16 unique lettes).

// It starts with the numbers 0-9, then the capital letters A-F, and lastly the
// numbers 10 and 11 to represent 16 and 17.

// The '0x' prefix is used to denote a hex number.

void HexadecimalDemonstration() {
  int hexadecimal_number = 0xF;
  std::cout << hexadecimal_number << '\n';  // Should print 15
}

// * ===== binary ===== *

// Prior to C++14, C++ doesn't provide support for binary literals, but you can
// use hexadecimal as a workaround using hex digits.

void BinaryLiteralWorkaround() {
  int bin{};     // assume 16-bit ints
  bin = 0x0001;  // assign binary 0000 0000 0000 0001 to the variable
  bin = 0x0002;  // assign binary 0000 0000 0000 0010 to the variable
  bin = 0x0004;  // assign binary 0000 0000 0000 0100 to the variable
  bin = 0x0008;  // assign binary 0000 0000 0000 1000 to the variable
  bin = 0x0010;  // assign binary 0000 0000 0001 0000 to the variable
  bin = 0x0020;  // assign binary 0000 0000 0010 0000 to the variable
  bin = 0x0040;  // assign binary 0000 0000 0100 0000 to the variable
  bin = 0x0080;  // assign binary 0000 0000 1000 0000 to the variable
  bin = 0x00FF;  // assign binary 0000 0000 1111 1111 to the variable
  bin = 0x00B3;  // assign binary 0000 0000 1011 0011 to the variable
  bin = 0xF770;  // assign binary 1111 0111 0111 0000 to the variable
}

// From C++14 onwards, you can use the '0b' prefix to indicate a binary literal.
// For example:

void BinaryDemonstration() {
  // You can use the quotation mark as a digit separator.
  int binary_number{0b1011'0010};
  long binary_value{2'132'673'462};
  std::cout << binary_number << '\n';
}

int main() {
  OctalDemonstration();
  HexadecimalDemonstration();
}