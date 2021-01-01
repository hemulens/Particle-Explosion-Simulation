#include "particle.h"
#include <stdlib.h>

namespace simulation {

  Particle::Particle() {
    _x = ((2.0 * rand()) / RAND_MAX) - 1;  // normalized to -1 – +1 on Cartesian coordinates
    _y = ((2.0 * rand()) / RAND_MAX) - 1;
  }

  Particle::~Particle() {

  }

} /* namespace simulation */

// Here we make particles move within a virtual space, independent of screen dimentions, then mapped to the screen (irrespective of screen size);