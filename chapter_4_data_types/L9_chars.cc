#include <iostream>

// * ====== chars ===== *

// Chars are integral data types, because they use numbers to store their value.
// The integer stored in a char is interpreted as an ASCII character. See
// https://www.asciitable.com/.

// The number is in the rangle 0-127, and is also known as an ASCII code or code
// point. Codes 0-31 and 127 are known as the "unprintable chars," and are
// mostly obsolete now.

// * ===== defining chars ====== *

// It is possible to define and print chars based only on their ASCII value. For
// example:

void PrintingChars() {
  char char_1{'a'};  // Best practice is to define chars with single quotes.
  std::cout << char_1 << '\n';

  char char_2{98};              // Code point for letter "b" (not preferred)
  std::cout << char_2 << '\n';  // prints "b"
}

// * ===== the input buffer ===== *

// Technically, the char type can hold more than one character, so if the
// program asks for one char but the user inputs many, the next time you ask for
// input, the next buffered char will be output.

void CharBuffer() {
  char char_1{};
  std::cin >> char_1;           // input "abcd"
  std::cout << char_1 << '\n';  // prints a

  std::cin >> char_1;   // reads from buffer
  std::cout << char_1;  // prints b
}

// ! best practices

// Always use single quotes to define char literals and escape sequences. This
// tells the ocmpiler what to expect and is more effecient.

// Other char types like wchar_t, char8_t, char16_t, and char32_t should be
// avoided because they are implementation-defined and deprecated.

int main() {
  PrintingChars();
  CharBuffer();
}