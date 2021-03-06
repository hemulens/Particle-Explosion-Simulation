#include "particle.h"
#include <math.h>
#include <stdlib.h>

namespace simulation {

  Particle::Particle() : _x(0),  // normalized to -1 – +1 on Cartesian coordinates
                         _y(0),
                         _direction(0),
                         _speed(0) {
                           init();
                         }

  // Old Particle init list for spontaneous particle motion
  // _x(((2.0 * rand()) / RAND_MAX) - 1),  // normalized to -1 – +1 on Cartesian coordinates
  // _y(((2.0 * rand()) / RAND_MAX) - 1), 
  // _xSpeed(0.001 * (((2.0 * rand())/RAND_MAX) - 1)),  // RAND_MAX is a large const int; rand() returns a random int value from 0
  // _ySpeed(0.001 * (((2.0 * rand())/RAND_MAX) - 1)) {}

  Particle::~Particle() {}

  void Particle::init() {
    _x = 0;
    _y = 0;
    _direction = (2 * M_PI * rand())/RAND_MAX;  // direction (angle) is measured in radians, not in 360 degrees, but in 2*PI, i.e. 0 – 6.3
    _speed = (0.04 * rand())/RAND_MAX;
    _speed *= _speed;  // By squaring the speed, the avg distance btw particles increases
  }

  void Particle::update(int interval) {
    // Circular motion pattern
    _direction += interval * 0.0003;  // curl around the particle direction
    _xSpeed = _speed * cos(_direction);
    _ySpeed = _speed * sin(_direction);
    _x += _xSpeed * interval;  // making sure the amount the particle is moved by is proportional to the amount of time sinsce we last moved the particle, thus ensuring it will move at a similar speed on slower systems.
    _y += _ySpeed * interval;
    // Make particles reappear at initial position, if they go off the screen
    if (_x < -1 || _x > 1 || _y < -1 || _y > 1) {
      init();
    }
    // Reinitialize particles, if the random value is < RAND_MAX / 100
    if (rand() < RAND_MAX / 100) {
      init();
    }

    // Old Particle update method for spontaneous particle motion
    // _x += _xSpeed;
    // _y += _ySpeed;
    // // Reverse the speed (and hence direction) if reaches end of the screen
    // if (_x <= -1.0 || _x >= 1.0) {
    //   _xSpeed = -_xSpeed;
    // }
    // if (_y <= -1.0 || _y >= 1.0) {
    //   _ySpeed = -_ySpeed;
    // }
  }

} /* namespace simulation */

// Here, we make particles move within a virtual space, independent of screen dimentions, then mapped to the screen (irrespective of screen size);