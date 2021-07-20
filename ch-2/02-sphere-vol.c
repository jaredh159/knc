#include <stdio.h>
#include <math.h>

int main(void) {
  float radius = 30.0f;
  float volume = (4.0f / 3.0f) * M_PI * (radius * radius * radius);
  printf("The volume of a sphere with radius=%f is %f\n", radius, volume);
  return 0;
}

