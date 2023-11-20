#include "../definitions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

position_t *calc_position(flight_t *flight, float time) {
  position_t *future_position = malloc(sizeof(position_t));
  int distance;
  distance = time * flight->speed;
  future_position->x = distance * cos(flight->heading) + flight->x;
  future_position->y = distance * sin(flight->heading) + flight->y;
  future_position->z = flight->z;
  // printf("Flight:%d %f %f %f\n", flight->id, future_position->x,
  // future_position->y, future_position->z);
  return future_position;
}
