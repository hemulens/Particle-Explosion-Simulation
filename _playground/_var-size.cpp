#include <iostream>
#include <typeinfo>
#include <climits>

// Experiment with variable sizes
unsigned char red = 0x12;
unsigned char green = 0x34;
unsigned char blue = 0x56;
unsigned char alpha = 0xFF;
// unsigned int color = alpha;  // 8 digit unsigned int; 8 digits in hex = 4 bytes = 32 bits
unsigned int color = 0;

unsigned char c;
unsigned long l;

// Experiment with max int8_t size
int8_t int8_t1 = 127;  // signed max 127; if printed without "unsigned(int8_t1)", yields invisible ASCII values up to number 32 or higher
uint8_t uint8_t1 = 255;  // unsigned max 255
int16_t int16_t1 = 32767;  // signed max 32767
uint16_t uint16_t1 = 65535;  // unsigned max 65535
int32_t int32_t1 = 2147483647;  // signed max 2 147 483 647
uint32_t uint32_t1 = 4294967295;  // unsigned max 4 294 967 295
int int1 = 2147483647;  // signed max 2 147 483 647
unsigned int uint1 = 4294967295;  // unsigned max 4 294 967 295
int64_t int64_t1 = 9223372036854775807;  // signed max 9 223 372 036 854 775 807 (why not 9 223 372 036 854 776 000 ?)
uint64_t uint64_t1 = 9223372036854775807;  // unsigned max 18 446 744 073 709 551 615 (why not 18 446 744 073 709 552 000 ?)
long long1 = 9223372036854775807;  // signed max 9 223 372 036 854 775 807 (why not 9 223 372 036 854 776 000 ?)
unsigned long ulong1 = 9223372036854775807;  // unsigned max 18 446 744 073 709 551 615 (why not 18 446 744 073 709 552 000 ?)

int main() {
  // std::cout << "Size of unsigned int color = " << sizeof(color) << std::endl;
  // std::cout << "Size of unsigned char red = " << sizeof(red) << std::endl;
  // std::cout << "Size of unsigned char c = " << sizeof(c) << std::endl;
  // std::cout << "Size of unsigned long l = " << sizeof(l) << std::endl;
  std::cout << "\n";
  
  std::cout << "Size of int8_t = " << sizeof(int8_t) << "; value = " << int8_t1  << "; unsigned value = " << unsigned(int8_t1) << "; type = " << typeid(int8_t1).name() << "; limit = " << std::numeric_limits<int8_t>::max() << std::endl;
  
  std::cout << "Size of uint8_t = " << sizeof(uint8_t1) << "; value = " << uint8_t1 << "; unsigned value = " << unsigned(uint8_t1) << "; type = " << typeid(uint8_t1).name() << "; limit = " << std::numeric_limits<uint8_t>::max() << std::endl;

  std::cout << "Size of int16_t = " << sizeof(int16_t1) << "; value = " << int16_t1 << "; unsigned value = " << unsigned(int16_t1) << "; type = " << typeid(int16_t1).name() << "; limit = " << std::numeric_limits<int16_t>::max() << std::endl;

  std::cout << "Size of uint16_t = " << sizeof(uint16_t1) << "; value = " << uint16_t1 << "; unsigned value = " << unsigned(uint16_t1) << "; type = " << typeid(uint16_t1).name() << "; limit = " << std::numeric_limits<uint16_t>::max() << std::endl;

  std::cout << "Size of int32_t = " << sizeof(int32_t1) << "; value = " << int32_t1 << "; unsigned value = " << unsigned(int32_t1) << "; type = " << typeid(int32_t1).name() << "; limit = " << std::numeric_limits<int32_t>::max() << std::endl;

  std::cout << "Size of uint32_t = " << sizeof(uint32_t1) << "; value = " << uint32_t1 << "; unsigned value = " << unsigned(uint32_t1) << "; type = " << typeid(uint32_t1).name() << "; limit = " << std::numeric_limits<uint32_t>::max() << std::endl;

  std::cout << "Size of int = " << sizeof(int1) << "; value = " << int1 << "; unsigned value = " << unsigned(int1) << "; type = " << typeid(int1).name() << "; limit = " << std::numeric_limits<int>::max() << std::endl;

  std::cout << "Size of unsigned int = " << sizeof(uint1) << "; value = " << uint1 << "; unsigned value = " << unsigned(uint1) << "; type = " << typeid(uint1).name() << "; limit = " << std::numeric_limits<unsigned int>::max() << std::endl;
  
  std::cout << "Size of int64_t = " << sizeof(int64_t1) << "; value = " << int64_t1 << "; unsigned value = " << unsigned(int64_t1) << "; type = " << typeid(int64_t1).name() << "; limit = " << std::numeric_limits<int64_t>::max() << std::endl;

  std::cout << "Size of uint64_t = " << sizeof(uint64_t1) << "; value = " << uint64_t1 << "; unsigned value = " << unsigned(uint64_t1) << "; type = " << typeid(uint64_t1).name() << "; limit = " << std::numeric_limits<uint64_t>::max() << std::endl;

  std::cout << "Size of long = " << sizeof(long1)  << "; value = " << long1 << "; unsigned value = " << unsigned(long1) << "; type = " << typeid(long1).name() << "; limit = " << std::numeric_limits<long>::max() << std::endl;

  std::cout << "Size of unsigned long = " << sizeof(ulong1) << "; value = " << ulong1 << "; unsigned value = " << unsigned(ulong1) << "; type = " << typeid(ulong1).name() << "; limit = " << std::numeric_limits<unsigned long>::max() << std::endl;

  std::cout << "Maximum value that can be stored in unsigned long long int = " << ULLONG_MAX << std::endl;
  
  long long int e = 0;

  std::cout << e - 1 << std::endl;

  return 0;
}

/*
Resources: 
- https://www.cplusplus.com/doc/tutorial/variables/
- https://www.cplusplus.com/forum/beginner/175177/
- In GNU / LLVM compilers, to decipher a, k, s, f, etc., use "c++filt 'symbol'" (e.g. c++filt a) in the terminal: https://ftp.gnu.org/old-gnu/Manuals/binutils-2.12/html_node/binutils_11.html
- 
*/
