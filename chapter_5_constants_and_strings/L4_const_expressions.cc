#include <iostream>

// * ===== as-if statements ===== *

// In C++, compilers are given a lot of leeway to optimize programs. The as-if
// rule says that the compiler can modify a program however it likes in order to
// produce more optimized code, so long as those modifications do not affect a
// program’s “observable behavior”.

// * ===== compile-time evaluation of expressions ===== *

// C++ is able to evaluate some expressions at compile-time. When this happens,
// the compiler replaces the expression with the result of the expression.

// * ===== const expressions ===== *

// A constant expression only contains compile-time constants, and
// functions/operations that support compile-time evaluation. Essentially, it is
// an expression that only contains things that can be evaluated at
// compile-time.

// A compile-time constant is a constant who value must be known at compile
// time. This includes:

// 1. literals
// 2. constexpr variables
// 3. const integral variables with a constant expression initializer (e.g.
// const int {5};)
// 4. non-type template parameters
// 5. enumerators

// Const variables that are not compile time constants are called runtime
// constants. Runtime constants cannot be used in a const expression. Const
// non-integral varibales are always runtime constants.

// An expression that is not a constant expression is sometimes called a runtime
// expression. For example, 'std::cout << x' is a runtime expression because 'x'
// is not a compile-time constant and operator<< doesn't support compile-time
// evaluation.

inline int GetNumber() {
  int user_input{};
  std::cin >> user_input;
  return user_input;
}

void ConstExpressions() {
  // Non-const variables are always non-constants:
  int a{5};  // 5 is a constant expression

  // Compile-time constants needs to be initialized with integral types:
  const int b{5.0};  // 5.0 is a constant expression, but isn't an integral type
                     // so b is a runtime constant.

  // Const integral variables with a constant expression initializer are
  // compile-time constants:
  const int c{5};       // 5 is a constant expression
  const int d{c + 5};   // c + 5 is a constant expression
  const long e{c + 2};  // c + 2 is a constant expression

  // Other const variables are runtime constants:
  const int f{a};
  const int g{a + 1};
  const int h{a + c};
  const int i{GetNumber()};
}

// * ===== why care about constant expressions ===== *

// Constant expressions are always eligible for compile-time evaluation, meaning
// they are more likely to be optimized at compile-time. This produces faster
// and smaller code.

// With runtime expressions, only the type of the expression is known at
// compile-time. With constant expression, both the type AND the value of the
// expression is known at compile-time. This allows us to do compile-time
// sanity checking of those values. If such a value does not meet our
// requirements, we can fail the build, allowing us to identify and fix the
// issue immediately. The result is code that is safer, easier to test, and
// more difficult to misuse.

// * ===== constant folding ===== *

// The act of optimizing compile-time subexpressions of runtime expressions is
// called constant folding. For example:

void ConstantFolding() {
  std::cout << 3 + 7 << '\n';  // 3 + 7 is a compile-time expression that is
                               // optimized away by constant folding.
}

// This type of optimization is also possible with runtime expressions:

void RuntimeConstantFolding() {
  int x{7};  // x is non-const
  std::cout << x
            << '\n';  // The compiler can optimize x away because it realized
                      // that x doesn't change throughout the program
}

// but since g++ has to figure out if x changes or not, it is generally better
// to do this with consts.

// * ===== debugging issues ===== *

// Optimization can make programs harder to debug. When the compiler optimizes a
// program, variables, expressions, statements, and function calls may be
// rearranged, altered, replaced with a value, or even removed entirely. Such
// changes can make it hard to debug a program effectively.

// When you step into a function that has been optimized away, the debugger will
// just skip over it. If that happens, const expressions are likely the reason.

int main() {
  ConstantFolding();
  RuntimeConstantFolding();
}