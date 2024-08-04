#include <iostream>

// * ===== literals ===== *

// Literals are values inserted directly into the code. For example, std::cout
// << "Hello, world" contains "Hello, world" as a C-style string literal. There
// are sometimes also called literal constants because their value cannot be
// redefined (5 is always 5 in C++).

// * ===== literal suffixes ===== *

// C++ automatically infers the type of the literal from looking at it. If the
// inferred type is not appropriate, you can add a suffix to force the compiler
// to case to that type. These are called "literal suffixes." Most literal
// suffixes are rare except for "f."

void LiteralSuffixes() {
  std::cout << 5L << '\n';  // 5 is now type long int
  std::cout << 5u << '\n';  // 5 is now type unsigned int
}

// Note: Initializing a float variable without an "f" literal suffix often
// results in stange compiler problems. This is because C++ automatically tries
// to convert the (default) double value into a float value so that the type
// would match. This is a narrowing conversion that causes a loss of precision.

// * ===== scientific notation on float literals ===== *

// There are two ways to define a double literal:

void ScientificNotation() {
  double a{3.1415926};  // The normal way
  double b{6.09e23};    // Using scientific notation
  std::cout << a << " " << b << '\n';
}

// * ===== C-style string literals ===== *

// C-style string literals are string literals inherited from the C language.
// There are two non-obvious things about them:

// 1. Every C-style string ends with the null terminator character '\0', which
// has an ASCII value of 0. A string with a null terminator is called a
// "null-terminated string."

// 2. C-style strings are consts created at the start of the program and is
// garunteed to exist for the rest of the program.

// * ===== magic numbers ===== *

// A magic number is an integral literal that either has an unclear meaning or
// may need to be changed later.

void SetMax(int) {}

void MagicNumbers() {
  const int num_classrooms{4};

  // Here it's not immediately obvious what the literal 30 does
  const int total_students{num_classrooms * 30};

  // Here it's impossible to tell what the 30 is supposed to mean
  SetMax(30);
}

void NoMagicNumbers() {
  const int num_classrooms{4};
  const int num_students{30};

  // Now it's clear what the variable is meant to be doing
  const int total_students{num_classrooms * num_students};

  const int max_name_length{30};

  // Now there is no confusion about the literal
  SetMax(max_name_length);
}

// However, literals considered obvious (like conversion factors) are not
// considered magic. For exmaple:

double KilometersToMeters(int num_kilometers) {
  return num_kilometers * 1000;  // Here, 1000 is an obvious conversion factor.
}

int main() {
  LiteralSuffixes();
  ScientificNotation();
}