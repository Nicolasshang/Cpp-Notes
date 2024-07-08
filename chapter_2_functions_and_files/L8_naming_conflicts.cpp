#include <iostream>

// * =====Naming collisions===== *

// C++ requires all of its identifiers to be non-ambiguous. If two identical
// identifiers are introduced to a program, then either the compiler or linker
// will throw an error.

// A naming collision happens in one of two cases:
// 1. Two (or more) identically named functions or global variables are
// introduced into two separate files of the same program. This results in a
// linker error.
// 2. Two (or more) identically named functions and variables are introduced
// into the same file. This will lead to a compiler error.

// * =====Scope regions===== *

// A scope region is an area of source code where all declared identifiers are
// considered distinct from names declared in other scopes. Two identical names
// can be declared in two separate scope regions without causing a naming
// collision.
// The body of a function is an example of a scope region.

// * =====Namespaces===== *

// Namespaces provide another type of scope region called namespace scope.
// They allow you to declare names inside of it for the purposes of
// disambiguation.

// Only declarations and definitions can appear inside a namespace, not
// executable statements. However, you can define a function containing
// executable statements inside a namespace.

// * =====The global namespace===== *

// Any identifier that is not in a class, function or namespace is is the global
// namespace (also called the global scope).

// * =====The std:: namespace===== *

// "std::" is a scope resolution qualifier. "std::cout" means that "count" in
// contained in the standard namespace.
// You can also use "using namespace std" at the start of the program, but don't
// do that as it can introduce naming collisions.

void Foo(int bar) {  // Although Foo() is defined in the global namespace, bar
                     // is still in the function's local scope.
  std::cout << bar << "\n";
}

int main() {}