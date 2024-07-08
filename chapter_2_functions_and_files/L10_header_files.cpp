// * =====The purpose of header files===== *

// When you need a bunch of functions in a program, it becomes tedious to
// forward declare everything in the script.

// Header files allow us to put declarations in one location and then import
// them wherever we need them. This can save a lot of typing in multi-file
// programs.

// It is best practice to use the .h suffix on header files.

// * =====Parts of a header file===== *

// There are two parts to a header file:
// 1. Header guards, which prevents the file from being preprocessed into a
// translation unit more than once.
// 2. The forward declarations and identifiers we want other files to see.

// * =====Types of #include===== *

// When the preprocessor sees the #include directive, it replaces the macro with
// all the contents of the specified file.

// There are two types of #include statements:
// 1. #include <file_name>, which is used for stdlib stuff, like iostream.
// 2. #include "file_name.h", which is used for user-defined header files.

// The header files are usually in the same folder as the .cpp file that
// implements the header file's declarations.

// #include "../include/add.h"

#include <iostream>

int main() {
  // std::cout << Add(1, 2) << "\n";
}

// * Put this file and the files below into a separate folder and compile them
// * all together:

// * Add.h

// int Add(int, int);

// * Add.cc

// #include "../include/add.h"

// int Add(int x, int y) { return x + y; }