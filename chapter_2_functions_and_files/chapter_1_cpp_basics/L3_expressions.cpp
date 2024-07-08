#include <iostream>

int five() { return 5; }

int six() { return 6; }

int main() {
  // Statements are what the g++ compiler uses if it wants to calculate a value.
  // This is distinct from statements, which are used to perform some action.

  // A subexpression is an expression used as an operand. For instance, in the
  // expression "x = 4 + 5", "x" and "4 + 5" are subexpressions. A full
  // expression is an expression that is not a subexpression. "x = 4 + 5" is a
  // full expression. A compound expression is an expression that uses two or
  // more uses of operators. "x = 4 + 5" is a compounds operator as it includes
  // use of both the "=" operator and the "+" operator.

  int x = 4 + 5;

  // Whenever you need to use a single value, use a value-producing expression
  // instead, and it will work just fine.

  for (int i = 0; i < (five() + six()); i++) {
    std::cout << i << "\n";
  }
}