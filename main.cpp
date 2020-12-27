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

  // Main window
  SDL_Window *window = SDL_CreateWindow("Fire Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  // Check that the window was successfully created
  if (window == NULL || window == nullptr) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    SDL_Quit();
    return 2;  // returning a positive int means an error occurred
  }

  // Renderer object
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);  // index: the index of the rendering driver to initialize, or -1 to initialize the first driver supporting the requested flags; flags: SDL_RENDERER_PRESENTVSYNC – present is synchronized with the refresh rate (it helps prevent rendering at the time when screen is rendering)
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);  // format (2nd arg) is a number of possible constants (enum), depending on how many bites you want to represent one pixel; SDL_PIXELFORMAT_RGBA8888 uses one byte for each pixel. Access (3rd arg) is the way we are writing to the texture

  // Check if renderer is absent
  if (renderer == NULL || renderer == nullptr) {
    printf("Could not create renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }
  // Check if texture is absent
  if (texture == NULL || texture == nullptr) {
    printf("Could not create texture: %s\n", SDL_GetError());
    SDL_DestroyRenderer(renderer);
	  SDL_DestroyWindow(window);
    SDL_Quit();
    return 4;
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
  SDL_DestroyRenderer(renderer); // Destroy renderer
  SDL_DestroyTexture(texture); // Destroy texture
  SDL_DestroyWindow(window);  // Destroy window
  SDL_Quit();
}