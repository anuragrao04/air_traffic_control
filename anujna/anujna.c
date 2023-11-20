#include "../definitions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

position_t *calc_position(flight_t *flight, float time) {
  position_t *future_position = malloc(sizeof(position_t));
  float distance;
  distance = time * flight->speed;
  future_position->x = distance * cos(flight->heading) + flight->x;
  future_position->y = distance * sin(flight->heading) + flight->y;
  future_position->z = flight->z;
  return future_position;
}
