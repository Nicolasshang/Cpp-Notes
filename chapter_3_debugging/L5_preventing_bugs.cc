// * ===== How to minimize errors ===== *

// There are a few ways to minimize errors whereever possible:

// 1. Follow best practices.
// 2. Don’t program when tired or frustrated. Take a break and come back later.
// 3. Understand where the common pitfalls are in a language (all those things
// we warn you not to do).
// 4. Don’t let your functions get too long.
// 5. Prefer using the standard library to writing your own code, when possible.
// 6. Comment your code liberally.
// 7. Start with simple solutions, then layer in complexity incrementally.
// 8. Avoid clever/non-obvious solutions.
// 9. Optimize for readability and maintainability, not performance.

// * ===== Refactoring code ===== *

// As you add more changes to your code's functionality ("bahavioral changes"),
// functions tend to get long, and that decreases reasability. When it grows to
// more than a vertical screen's worth of height, it probably needs refactoring.

// Refactoring is the process of breaking a complex system down into simpler
// segments, which can mean seperating a function into several smaller
// functions, et cetera. The process is a "structural change."

// Note: trying to perform a behavioral and structural change at the same time
// tends to introduce errors, so don't do that.

// * ===== Defensive programming ===== *

// Defensive programming is a paradigm where the programmer anticipates all the
// ways their can be misused by other libraries, users, et cetera.

// * ===== Unit testing ===== *

// Unit testing is a software development technique where the validity of
// individual code segments are tested. There are also third-party frameworks,
// like Catch2 and Googletest.

// * ===== Constraints ===== *

// Constraint-based techniques use some extra code to check if some expectations
// were violated or not. For instance, if a function expects a positive integer,
// we can check if the argument is negative. If so, then we catch the error
// immediately.

// A better way to do this is static_assert.

// * ===== Static analysis tools ===== *

// Static analysis tools, often known as "linters," are tools that can spot
// bugs, stylistic errors, and suspicious code. The term originated from a C
// language utility that examined Unix source code.

int main() {}