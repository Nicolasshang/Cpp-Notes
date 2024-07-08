// * ===== VS Code auto debugger features ===== *

// Stepping is the process of executing the program statement by statement. VS
// Code offers a few stepping features:

// 1. "Step into" executes the next statement in the normal execution path of
// the program, and the pauses execution so we can inspect the program through
// the debugger.

// 2. "Step over" is like "step into," but executes entire function calls
// whenever it encounters one without stopping (doesn't step over each and every
// line of the called function). It will pause after the function call is
// finished.

// 3. "Step out" executes all remaining code in the function currently being
// executed until it returns something. This is useful whenever you are suck
// inside a function you don't want to debug.

// * ===== Run to cursor ===== *

// By right-clicking in debugging mode, you can select "run to cursor" and the
// program will run to where your cursor currently is.

// * ===== Breakpoints ===== *

// You can create breakpoints by clicking on the red circle to the left of the
// number line. The code pauses execution every time it encounters a breakpoint.

// * ===== The watch window ===== *

// One cool trick in the watch window (used for watching variables) is that you
// can evaluate arithmetic on them. For instance, you can watch i * 2 instead of
// just i.

// * ===== The call stack ===== *

// The call stack is a list of all the active functions that have been called to
// get to the current point of execution. The call stack includes an entry for
// each function called, as well as which line of code will be returned to when
// the function returns. Whenever a new function is called, that function is
// added to the top of the call stack. When the current function returns to the
// caller, it is removed from the top of the call stack, and control returns to
// the function just below it.

#include <iostream>
#include <string>

std::string AppendString(std::string string_1, std::string string_2) {
  return string_1 + string_2;
}

int main() {
  std::string string_1 = "Test string 1";
  std::string string_2 = "Test string 2";
  for (int i = 0; i < 1000000000; i++) {
    string_2 = AppendString(string_1, string_2);
    std::cout << string_2 << "\n";
  }
}