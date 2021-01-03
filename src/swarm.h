#ifndef SWARM_H_
#define SWARM_H_

#include "particle.h"

namespace simulation {

  class Swarm {
    public:
      Swarm();
      virtual ~Swarm();  // virtual destructor is needed to prevent undefined behavior when deleting a derived class object using a pointer of base class type; more: https://www.geeksforgeeks.org/virtual-destructor/
      const static int NPARTICLES{5000};
      const Particle *const getParticles();  // const pointer - the pointer can't be pointed anywhere else; the particles can't be changed either using the pointer returned
      void update(int elapsed);

    private:
      Particle *const _particles;  // const pointer to a particle (which itself isn't a const)
      int _lastUpdateTime;
  };

} /* namespace simulation */

#endif  /* SWARM_H_ */