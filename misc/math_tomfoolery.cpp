#include <stdio.h>

int main() {
  printf("%i %i %c %i %i %c %i %i %c %i %i %s",
         '1' + '5' + '9',  // 159
         '9' - '2',        // 7
         '9' - 2,          // still 7
         '9' - 2,          // lol jk it's 55
         '5' + 2,          // 55 (☉_☉)
         '5' + 2,          // actually no, it's 7
         1 * 1,            // one
         0 * '1',          // zero
         '0' * '1',        // fuck yeah still zero
         '1' * '1',        // 2401 щ(°ロ°щ)
         '1' * '0',        // gimme my zero back!
         "¯\\_(ツ)_/¯");

  return 0;
}