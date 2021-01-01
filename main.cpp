#include <SDL.h>

#include "screen.h"
#include "swarm.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace simulation;

int main() {

  srand(time(NULL));

  Screen screen;

  if (!screen.init()) {
    std::cout << "Failed initializing Screen" << std::endl;
  }

  Swarm swarm;
  int elapsed;
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char alpha{255};

  // Main "game loop"
  while (true) {
    // Update particles
    // Draw particles
    elapsed = SDL_GetTicks();  // returns the number of milliseconds since the program started
    red = (unsigned char)((sin(elapsed * 0.0001) + 1) * 128);  // sin(x) takes a number and returns a value in the range on -1 to +1; * 0.001 makes range shorter to ensure a smooth transition. Converted from double to int to discard the decimal remainder to return max of 256. Converted to char again: (unsigned char)(...) makes sure we are doing a cast (i.e. discarding remainder of decimal points). Change speed: 0.001 => 0.0001
    green = (unsigned char)((sin(elapsed * 0.0002) + 1) * 128);
    blue = (unsigned char)((sin(elapsed * 0.0003) + 1) * 128);

    const Particle *const particles = swarm.getParticles();  
    for (int i = 0; i < Swarm::NPARTICLES; i++) {
      Particle particle = particles[i];
      // Mapping particles
      int x = (particle._x + 1) / 2 * Screen::SCREEN_WIDTH; 
      int y = (particle._y + 1) / 2 * Screen::SCREEN_HEIGHT;
      screen.setPixel(x, y, red, green, blue, alpha); 
    }
    
    /* // Checker of max hex color value
    int max = 0;  // max value checker
    if (green > max) max = green;  // max value checker
    std::cout << green << std::endl;
    std::cout << "Max: " << max << std::endl;  // max value checker
    */

    /* // Draw the entire screen
    for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
      for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
        screen.setPixel(x, y, red, green, blue, 255);
      }
    }
    */

    /* // Experiment – setting a white pixel
    screen.setPixel(400, 300, 255, 255, 255, 255);
    */
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