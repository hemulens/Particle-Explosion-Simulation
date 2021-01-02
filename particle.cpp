#include "particle.h"
#include <stdlib.h>

namespace simulation {

  Particle::Particle() : _x(((2.0 * rand()) / RAND_MAX) - 1),  // normalized to -1 – +1 on Cartesian coordinates
                         _y(((2.0 * rand()) / RAND_MAX) - 1), 
                         _xSpeed(0.001 * (((2.0 * rand())/RAND_MAX) - 1)),  // RAND_MAX is a large const int; rand() returns a random int value from 0
                         _ySpeed(0.001 * (((2.0 * rand())/RAND_MAX) - 1)) {}

  Particle::~Particle() {}

  void Particle::update() {
    _x += _xSpeed;
    _y += _ySpeed;
    // Reverse the speed (and hence direction) if reaches end of the screen
    if (_x <= -1.0 || _x >= 1.0) {
      _xSpeed = -_xSpeed;
    }
    if (_y <= -1.0 || _y >= 1.0) {
      _ySpeed = -_ySpeed;
    }
  }

} /* namespace simulation */

// Here, we make particles move within a virtual space, independent of screen dimentions, then mapped to the screen (irrespective of screen size);