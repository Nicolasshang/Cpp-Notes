#include <iostream>

int Add(
    int x,
    int y);  // This is a forward declaration (also called a function
             // prototype). Because we are calling Add() in both DoSomething()
             // and main(), we can't move it to the back. Instead, this header
             // tells the compiler what Add() is supposed to look like.

int DoSomething() { return Add(1, 2); }

int main() { std::cout << Add(3, 4) << "\n"; }

int Add(int x, int y) {  // Compiles with no errors. Also, it is best practice
                         // to keep the parameter
  // names in both the forward and normal declarations so you don't lose track
  // of them.
  return x + y;
}

// =====Clarification=====

// A "declaration" is something that tells the compiler about an
// identifier and its associated type information. Examples include "void
// Foo(int a)" and "int x".

// A "definition" is anything that implements a function or instantiates a
// variable. Definitions are also declarations. Examples include "int x" or a
// function definition that has a body.

// A "pure declaration" is any declaration that's not a definition. These are
// mostly forward declarations.

// "Initialization" is the process of providing a value for a defined object,
// like "int x = 2". Here, "2" is the initializer.

// =====The One Definition Rule (ODR)=====

// The ODR rule has three parts.
// 1. Within one file in a given scope, each function, variable, type, or
// template must have only one definition.
// 2. Within a program, each function and variable can only have one definition.
// 3. Types, templates, inline functions, and inline variables are allowed to
// have duplicate definitions in different files, so long as each definition is
// identical.