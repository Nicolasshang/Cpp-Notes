#include <cstddef>
#include <cstdint>
#include <iostream>

// * ===== fixed-width ints ===== *

// The memory size for an int in C++ is not fixed. It only provides a minimum
// size, not a maximum. This dates back to early C which opted to keep the size
// of an int open for individual compiler implementation.

// This is really bad in the modern day because a program that assumes an int is
// 4 bytes will stop working on an architecture where an int is 2 bytes.

// To address the above issues, C99 defined a set of fixed-width integers (in
// the stdint.h header) that are guaranteed to be the same size on any
// architecture.

void FixedWidthInts() {
  std::int8_t
      a{};  // 1 byte signed (treated like a signed char on many systems)
  std::uint8_t
      b{};  // 1 byte unsigned (treated like an unsigned char on many systems)
  std::int16_t c{};   // 2 byte signed
  std::uint16_t d{};  // 2 byte unsigned
  std::int32_t e{};   // 4 byte signed
  std::uint32_t f{};  // 4 byte unsigned
  std::int64_t g{};   // 8 byte signed
  std::uint64_t h{};  // 8 byte unsigned
}

// * ===== int8_t and uint8_t behave like chars ===== *

// Due to an oversight in the C++ specification, most compilers define and treat
// std::int8_t and std::uint8_t (and the corresponding fast and least
// fixed-width types) identically to types signed char and unsigned char
// respectively. This means these 8-bit types may (or may not) behave
// differently than the rest of the fixed-width types, which can lead to errors.
// So, it is best not to use them.

// * ===== downsides of fixed-width ints ===== *

// The firts major downside is that fixed-width ints are not garunteed to be
// defined on all architectures. However, this normally shouldn't be an issue as
// most computers have standardized around x32/64 architectures.

// The second downside is that operations on fixed-width integers can be slower
// than regular ints. This is because fixed-width ints leave a bigger memory
// footprint, counteracting the compiler being able to understand the type
// faster.

// * ===== fast and least integers ===== *

// To adress the above two issues, C++ created the fast integers:
// std::int_fast#_t and std::uint_fast#_t. It provides the fastest
// signed/unsigned integer type with a width of at least # bits (where # = 8,
// 16, 32, or 64). For example, std::int_fast32_t will give you the fastest
// signed integer type that’s at least 32 bits.

// The least types (std::int_least#_t and std::uint_least#_t) provide the
// smallest signed/unsigned integer type with a width of at least # bits (where
// # = 8, 16, 32, or 64). For example, std::uint_least32_t will give you the
// smallest unsigned integer type that’s at least 32 bits.

void FastAndLeastInts() {
  std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
  std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
  std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
  std::cout << '\n';
  std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
  std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
  std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
}

// However, one major downside is that since the fastest integer type of
// different architectures might vary, there are cases where the program will
// behave differently on a different OS. Additionally, fast types might induce
// memory wastage if their actual size is larger than indicated by their name.

// ! Integral types best pratices:

// 1. Prefer int if the value of the variable doesn't matter or if it is
// short-lived.
// 2. Prefer std::int#_t if a value need a guaranteed range.
// 3. Prefer std::uint#_t when doing bit manipulation or where well-defined
// wrap-around behavior is required.

// Avoid the following:

// 1. Short and long ints. Use a fixed-width type instead.
// 2. Fast and least integers, 8-bit fixed-width integers.
// 3. Any compiler-specific fixed-width integers.

// * ===== std::size_t ===== *

// std::size_t is an implementation-defined unsigned integral type. The compiler
// decides if it's an unsigned int, unsigned long, et cetera.

// It is usually best to use std::size_t with the <cstddef> header.

void SizeTDemo() {
  int x{5};
  std::size_t size_of_x = sizeof(x);
  std::cout << "\nsize of x: " << size_of_x << "\n";
}

int main() {
  FixedWidthInts();
  FastAndLeastInts();
  SizeTDemo();
}