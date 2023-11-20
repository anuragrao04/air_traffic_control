#include "../anujna/anujna.h"
#include "../definitions.h"
#include <math.h>
#include <stdio.h>

// Function to calculate the distance between two positions
double calculateDistance(position_t *a, position_t *b) {
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}

int checkCollision(flight_t *a, flight_t *b, float time) {
  position_t *future_position_a = calc_position(a, time);
  position_t *future_position_b = calc_position(b, time);
  double distance = calculateDistance(future_position_a, future_position_b);
  // printf("Distance between flight %d and flight %d is %f\n", a->id, b->id,
  // distance);
  return distance < MIN_SEPARATION_DISTANCE;
}

void resolveCollision(flight_t *a, flight_t *b, float time) {
  printf("Collision Detected! Flight %d CLIMB! flight %d DESCEND!\t YOU HAVE "
         "%f SECONDS!\n",
         a->id, b->id, time); // Move aircraft 'a' 500 units away
}

void collision_avoidance(flight_t *flights[], int num_flights) {
  int collision_found = 0;
  for (int i = 0; i < num_flights; i++) {
    for (int j = 0; j < num_flights; j++) {
      if (i == j) {
        continue; // a flight can't collide with itself
      } else {
        for (float k = 0; k < MIN_WARNING_SECONDS; k++) {
          // printf("%f\n", k);
          if (checkCollision(flights[i], flights[j], k)) {
            resolveCollision(flights[i], flights[j], k);
            collision_found = 1;
            break;
          }
        }
      }
      if (collision_found) {
        break;
      }
    }
    if (collision_found) {
      collision_found = 0;
      break;
    }
  }
}
