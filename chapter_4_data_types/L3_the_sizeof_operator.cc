// * ===== object sizes ===== *

// C++ doesn't enforce the memory size of data types. It only forces char to be
// one bit, but nothing says that a byte should be 8 bits for C++ to run.

// To find out how much space a data type takes up, you can use the sizeof()
// operator, like so:

#include <iomanip>
#include <iostream>

int main() {
  std::cout << std::left;  // Left justify output

  // The setw(16) function aligns the output by 16 spaces to the right.
  std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
  std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
  std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
  std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
  std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
  std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
  std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
  std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
  std::cout << std::setw(16) << "long double:" << sizeof(long double)
            << " bytes\n";
}

// Note: on modern computers, operations on fundamental data types are optimized
// down to the teeth so performance issues are generally not a concern.