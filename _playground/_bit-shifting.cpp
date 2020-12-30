#include <iostream>
#include <iomanip>

// void processColors(std::vector<Uint8> &rgba, Uint32 &color) {
//     for_each(rgba.begin(), rgba.end() - 1, [&color] (Uint8 c) {
//       color += c;
//       color <<= 8;
//     });
    
//     // color += red;
//     // color <<= 8;
//     // color += green;
//     // color <<= 8;
//     // color += blue;
//     // color <<= 8;
//     // color += alpha;
//   };

int main() {
  // color: 0x123456FF

  unsigned char red = 0x12;
  unsigned char green = 0x34;
  unsigned char blue = 0x56;
  unsigned char alpha = 0xFF;
  
  // unsigned int color = alpha;  // 8 digit unsigned int; 8 digits in hex = 4 bytes = 32 bits
  unsigned int color = 0;

  // color = color << 8;  // move values left by 8 bits = 1 byte = 2 digits (hex)
  // color = color << 24;  // move values left by 24 bits = 3 bytes = 6 digits (hex)
  color <<= 8;
  color += red;
  color <<= 8;  // left shift by 1 byte
  color += green;
  color <<= 8;
  color += blue;
  color <<= 8;
  color += alpha;

  std::cout << "Color = " << std::setfill('0') << std::setw(8) << std::hex << color << std::endl;
  
  // Experiment with variable sizes
  std::cout << "Size of unsigned int color = " << sizeof(color) << std::endl;
  std::cout << "Size of unsigned char red = " << sizeof(red) << std::endl;
  unsigned char c;
  std::cout << "Size of unsigned char c = " << sizeof(c) << std::endl;
  unsigned long l;
  std::cout << "Size of unsigned long l = " << sizeof(l) << std::endl;
  
  return 0;
}