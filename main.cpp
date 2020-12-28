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

  bool quit = false;
  SDL_Event event;

  // Main game loop
  while (!quit) {
    // Update particles
    // Draw particles
    // Check for messages/events (loop through all waiting events and process them)
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {  // Quit event is raised whenever we click "close" on a window
        quit = true;
      }
    }
  }

  screen.close();
  
  return 0;
}