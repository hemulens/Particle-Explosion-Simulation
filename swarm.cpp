#include "swarm.h"

namespace simulation {

  Swarm::Swarm() : _particles{new Particle[NPARTICLES]} {}

  Swarm::~Swarm() {
    delete [] _particles;  // []!
  }

  const Particle *const Swarm::getParticles() {
    return _particles;
  };

} /* namespace simulation */