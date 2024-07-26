#include <iomanip>
#include <iostream>

// * ===== floating point numbers ===== *

// There are three types of floating point numbers: a single-precision float, a
// double-precision double, and an extended-precision long double. C++ does not
// define the size of these types.

// Floating point numbers will almost always be IEEE 754 compliant. In this
// format a float is 4 bytes and a long is 8 bytes.

// The long double is wierd because depending on implementation, it may be
// 8-byte, 16-byte, or 80-bit.

void FloatingPointInts() {
  int a{5};       // 5 is an integer
  double b{5.0};  // If there is no suffix, the compiler assumes the literal is
                  // a double.
  float c{5.0f};  // The f suffix tells the compiler to treat it like a float
                  // instead.
}

// It is best practice to make sure the literals match the variable they are
// being assigned to. Otherwise, an uneccessary conversion might result.

// * ===== floating point precision ===== *

// The precision of a floating point number is how many sigfigs it can store
// without information loss.

// A float has 6 to 9 digits of precision and a double have between 15 to 18
// digits.

// * ===== outputting floats ===== *

// C++ asusmes that floats have 6 sigfigs, and will truncate off anything after
// that. In the example below, all values returned will have 6 sigfigs.

void OutputtingFloats() {
  std::cout << 9.87654321f << '\n';       // 9.87654
  std::cout << 987.654321f << '\n';       // 987.654
  std::cout << 987654.321f << '\n';       // 987654
  std::cout << 9876543.21f << '\n';       // 9.87654e+06
  std::cout << 0.0000987654321f << '\n';  // 9.87654e-05
}

// We can prevent g++ from truncating using output manipulators defined in
// <iomanip>. One such function is std::setprecision(int) which outputs a
// certain number of sigfigs.

void SetPrecision() {
  std::cout << std::setprecision(17);
  std::cout << 3.33333333333333333333333333333333333333f
            << '\n';  // Inaccurate result
  std::cout << 3.33333333333333333333333333333333333333
            << '\n';  // Accurate result
}

// * ===== rounding errors ===== *

// When precision is lost because a number can’t be stored precisely, this is
// called a rounding error.

// In the below example, a rounding error occurs because the program tries to
// output a 16-bit precision float with 17-bit precision.

void RoundingError1() {
  double f{0.1};
  std::cout << std::setprecision(6);
  std::cout << "precision 6: " << f << "\n";  // prints 0.1
  std::cout << std::setprecision(17);
  std::cout << "precision 17: " << f << "\n";  // prints 0.10000000000000001
}

// Arithmetic operations also tend to make errors grow. For instance:

void RoundingError2() {
  std::cout << std::setprecision(17);

  double double_1{0.1};
  std::cout << "double 1: " << double_1 << "\n";

  double double_2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1};
  std::cout << "double 2: " << double_2 << "\n";
}

// * ===== NaN and Inf ===== *

// There are two special floating-point values: NaN and Inf.

// Inf stands for positive or negative infinity, and NaN represents a wide rane
// of numbers like 0/0, infinity/infinity, and so forth.

void NanAndInf() {
  double zero{0.0};
  double posinf{5.0 / zero};  // positive infinity
  std::cout << posinf << '\n';

  double neginf{-5.0 / zero};  // negative infinity
  std::cout << neginf << '\n';

  double nan{zero / zero};  // not a number (mathematically invalid)
  std::cout << nan << '\n';
}

int main() {
  OutputtingFloats();
  SetPrecision();
  RoundingError1();
  RoundingError2();
  NanAndInf();
}