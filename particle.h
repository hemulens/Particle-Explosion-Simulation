#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace simulation {

  struct Particle {  // in struct, we need no getX() and getY() methods, which would slow down performace of the application
    public:
      Particle();
      virtual ~Particle();  // virtual destructor is needed to prevent undefined behavior when deleting a derived class object using a pointer of base class type; more: https://www.geeksforgeeks.org/virtual-destructor/
      void update(int interval);

      double _x;  // particle coordinates on the screen x & y
      double _y;  // double allows moving pixels bit by bit to other pixel slot by rounding numbers
      // double _xSpeed;
      // double _ySpeed;
      double _speed;
      double _direction;
      double _xSpeed;
      double _ySpeed;
  };

} /* namespace simulation */

#endif  /* PARTICLE_H_ */