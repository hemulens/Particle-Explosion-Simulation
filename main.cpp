#include <SDL.h>
#include "screen.h"

#include <iostream>
#include <stdio.h>

using namespace simulation;

int main() {

  Screen screen;

  if (!screen.init()) {
    std::cout << "Failed initializing Screen" << std::endl;
  }

  // Main game loop
  while (true) {
    // Update particles
    // Draw particles
    for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
      for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
        screen.setPixel(x, y, 128, 0, 255, 255);
      }
    }
    screen.setPixel(400, 300, 255, 255, 255, 255);
    // Draw screen
    screen.update();
    // Check for messages/events (loop through all waiting events and process them)
    if (!screen.processEvents()) {
      break;
    }
  }

  screen.close();
  
  return 0;
}