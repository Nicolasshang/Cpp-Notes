#include <iostream>

// * ===== constexpr ===== *

// If we just use compile-time constants, there is the problem that no type
// other than integral types can qualify. Additionally, it is usually not clear
// whether something is a runtime or compile-time const. For this reason, we
// introduce constexpr.