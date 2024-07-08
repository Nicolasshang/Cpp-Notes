#include <cmath>
#include <iostream>

// *=====The preprocessor===== *

// Before compilation, C++ goes through a step where the proprocessor makes
// various changes to the text of the code file. It does not alter the program's
// function in any way, however.
// The entire process of precompiling, compiling, and linking is called
// translation. When a preprocessor is finished with a program, that code is
// called a "translation unit".

// * =====Preprocessor directives====== *

// When you #include a file, it replaces the #include command with the contents
// of the file specified in the brackets.

// * ======Macro defines====== *

// The #define directive can be used to create a macro. In C++, a macro is a
// rule that dictates how input text is converted into output text. There are
// two types of macros: object-like macros, and function-like macros.

// Function-like macros are generally considered unsafe, and their usage can
// almost always be done with normal functions. Examples include:

// * =====Object-like macros with substitution text===== *

// You can define a rigid value for a #define macro, such as the value of pi.
// These should be avoided as there are better ways to do these things, such as
// constant variables.

// * =====Object-like macros without substitution text====== *

// Nothing is valid replacement text for a macro. When the preprocessor sees
// this, it will replace instances of it with nothing. This is useful for #ifdef
// directives, for example.

// * =====Conditional compilation===== *

// You can use the #ifdef macro to compile some statements if a certain
// condition is #defined, and #ifndef to compile something if something is not
// #defined. You must section off the macro using #endif.

// * =====#if 0 and #if 1===== *

// A block of code sectioned off using #if 0 and #endif will not be compiled, is
// if it is a block of comment. This provides a convenient way to "comment out"
// multi-line comments due to the fact that multi-line comments are
// non-nestable.
// To temporarily re-enable the block of code for compilation, change the "#if
// 0" to "#if 1".

// * =====Scope of directives===== *

// Directives are resolved before compilation from top to bottom. For this
// reason, it is best to #define outside of functions to avoid confusion.

// * =====Function-like macros===== *

// Function like macros have the syntax #define NAME_OF_FUNCTION(__VA_ARGS__)
// (// do something with the arguments).
// Often, people use the line continuation character \ to indicate to the
// preprocessor that the macro continues on the next line. This helps improve
// clarity in most use cases.

#define PI 3.1415926

#define TEMP_MACRO

#define SUM(a, b, c) (a + b + c)
#define AVERAGE(a, b, ...) \
  ((a + __VA_ARGS__) / b)  // The macro can end in an ellipsis, in which case,
                           // it works like an *args parameter in python.

#define PWR(a, b) (pow(a, b))
#define DEBUG(a, b)            \
  printf("value 1 = %d\n", a); \
  printf("value 2 = %d\n", b);

int main() {
  std::cout << PI << "\n";  // Prints "3.1415926"

#ifdef TEMP_MACRO
  std::cout << "The macro is defined"
            << "\n";  // Since we defined TEMP_MACRO already, this will compile.
#endif

#ifndef ANOTHER_TEMP_MACRO
  std::cout << "The macro is not defined"
            << "\n";  // Since ANOTHER_TEMP_MACRO has not been #defined yet,
                      // this will compile as well.
#endif

#if 0  // Doesn't throw an error
    std::cout << "This is in a #if 0 block, so it won't get executed" << "\n";
    /*Some
    multi
    line
    comment
    here*/
#endif

  std::cout << SUM(1, , 3)
            << "\n";  // Some of the macro parameters may be empty
  std::cout << AVERAGE(1, 2, 3)
            << "\n";  // Here, 3 is now part of the __VA_ARGS__ parameter in the
                      // AVERAGE() macro.
  DEBUG(PWR(100, 105), 50);  // Expands to printf("value 1 = %d\n", pow(100,
                             // 105)); / printf("value 2 = %d\n", 50);
}