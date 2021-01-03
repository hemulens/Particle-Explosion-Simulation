#include "swarm.h"

namespace simulation {

  Swarm::Swarm() : _particles(new Particle[NPARTICLES]),
                   _lastUpdateTime(0) {}

  Swarm::~Swarm() {
    delete [] _particles;  // []!
  }

  const Particle *const Swarm::getParticles() {
    return _particles;
  };

  void Swarm::update(int elapsed) {
    int interval = elapsed - _lastUpdateTime;
    for (int i = 0; i < Swarm::NPARTICLES; i++) {
      _particles[i].update(interval);
      // // Mapping particles
      // int x = (particle._x + 1) / 2 * Screen::SCREEN_WIDTH; 
      // int y = (particle._y + 1) / 2 * Screen::SCREEN_HEIGHT;
      // screen.setPixel(x, y, red, green, blue, alpha); 
    }
    _lastUpdateTime = elapsed;
  }

} /* namespace simulation */