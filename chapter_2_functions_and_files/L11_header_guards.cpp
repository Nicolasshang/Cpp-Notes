// * ===== Header guards ===== *

// When a program #includes multiple files, there can be naming conflicts. For
// example, if main.cpp #includes a header file that #includes a bunch of other
// header files, there is a chance that one really common header (like
// iostream.h) is included more than once. If that happens, main.cpp won't
// compile as some iostream functions will be subsituted more than one time into
// it.

// To solve this problem, we can use header guards, which are of the following
// syntax:

#ifndef FILE_NAME_HERE
#define FILE_NAME_HERE

inline int Foo();

#endif

// This makes sure that the declaration of Foo() in the file will only happen if
// the header file (aka the file name) hasn't already been defined somewhere
// else.

// However, one major problem is that the FILE_NAME_HERE variable has to be
// unique to every file; otherwise, we risk missing out on the contents of
// entire header files.

// * ===== Being included once into different files ===== *

// If you are including a header file in more than one .cc file at a time, a
// linker error will still occur. This is because both files will include the
// header file once in their own code, despite the header file itself being
// guarded.

// * ===== #pragma once ===== *

// A better method to guard header files is the pragma directive. The syntax is:

#pragma once

// Note: since #pragma once is not defined by the C++ standard, some compilers
// might not implement it.