#include <stdio.h>
#include <math.h>

int main(void) {
  float radius;
  printf("Enter a radius: ");
  scanf("%f", &radius);
  float volume = (4.0f / 3.0f) * M_PI * (radius * radius * radius);
  printf("The volume of a sphere with radius of %.3f is %.3f\n", radius, volume);
  return 0;
}

