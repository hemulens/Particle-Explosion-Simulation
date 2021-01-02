// Bitiwse "AND" operator
// Used for fetching r, g and b values from the int color variable.
// If curious, see Bitwise "OR" operator |

#include <iostream>

int main() {
  // int color{0x12345678};
  int color{0x123456};  // here, alpha value is missing on purpose (for simplicity)

  int example = color & 0xFF0000;  // single & in C++ makes a bitwise comparison; in bits, 0xFF0000 = 111111110000000000000000
  unsigned char red = (color & 0xFF0000) >> 16;  // shift the value 2 bytes (16 bits) along
  int green = (color & 0x00FF00) >> 8;  
  int blue = (color & 0x0000FF) >> 0;

  /*
  Single & in C++ makes a bitwise comparison in the following way:
  Color:  100010111101111011111011
  Mask:   111111110000000000000000 (which is this: 0xFF0000)
  Result: 100010110000000000000000
  */

  // Alternative (system-dependent)
  unsigned char _red = color >> 16;

  std::cout << std::hex << example << std::endl;
  std::cout << std::hex << (int)red << std::endl;
  std::cout << std::hex << green << std::endl;
  std::cout << std::hex << blue << std::endl;
  
  std::cout << std::endl;

  std::cout << std::hex << (int)_red << std::endl;

  return 0;
}