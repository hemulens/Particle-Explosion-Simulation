#include <iostream>
#include <cmath>
#include <SDL.h>

double i;

void Increase(double &n) {
  n = pow(n, 2);
}

int main() {
  i = 2;
  Increase(i);
  std::cout << "i = " << i << std::endl;
}