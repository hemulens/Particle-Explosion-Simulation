#include <SDL.h>

#include <iostream>
#include <stdio.h>

int main() {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init failed. Error: " << SDL_GetError() << std::endl;
    return 1;  // returning a positive int means an error occurred
  }

  SDL_Window *window = SDL_CreateWindow("Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 2;  // returning a positive int means an error occurred
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

  SDL_DestroyWindow(window);
  SDL_Quit();
}