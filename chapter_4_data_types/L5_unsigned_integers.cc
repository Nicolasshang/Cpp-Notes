#include <iostream>

// * ===== unsigned integers ===== *

// Unsigned integers are integers that can only store nonnegative whole numbers.

void UnsignedIntegers() {
  unsigned short a{};
  unsigned int b{};
  unsigned long c{};
  unsigned long long d{};
}

// Compared to signed integers, unsigned integers are store positive numbers
// that are twice as large.

// * ===== unsigned overflow ===== *

// When you define an unsigned integer larger than its range, the value wraps
// around to 0 and keep on going.

void UnsignedIntWraparound() {
  unsigned short number{65535};  // The largest 16-bit unsigned integer possible

  number++;
  std::cout << number << "\n";  // Should print 0

  number++;
  std::cout << number << "\n";  // Should print 1
}

// * ===== why avoid unsigned integers ===== *

// There are two major issues that makes unsigned ints difficult to use.

// Issue 1: easy to overflow
// The following program doesn't output the expected -1, but 4294967295.

void UnsignedIntOverflow() {
  unsigned int number{2};
  unsigned int number_2{3};

  std::cout << number - number_2 << "\n";
}

// Issue 2: mixing signed and unsigned ints
// In C++, if a mathematical operation like addition or comparison has one
// signed and one unsigned integer, the signed integer will usually be coverted
// to an unsigned integer.

void UnsignedIntAndSignedInt() {
  unsigned int unsigned_number{2};
  int signed_number{3};

  std::cout << unsigned_number - signed_number
            << "\n";  // Should print 4294967295
}

// Hence, the best practice is to not use unsigned integers at all.

// * ===== usecases of unsigned ints ====== *

// One of the usecases of unsigned ints is bit manipulation. They are also
// useful where the well-defined wraparound behaviour is required, like in
// cyptography and random number generation.

// Use of unsigned numbers is still unavoidable is some cases, namely array
// indexing and arduino systems.

int main() {
  UnsignedIntWraparound();
  UnsignedIntOverflow();
  UnsignedIntAndSignedInt();
}