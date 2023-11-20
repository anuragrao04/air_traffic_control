#ifndef DEFINITIONS
#define DEFINITIONS
#define MAX_SIZE 100
#define MIN_SEPARATION_DISTANCE 500.0
#define MIN_WARNING_SECONDS 120
typedef struct flight {
  int id;
  // current x y z prositions
  float x;
  float y;
  float z;
  // current speed and direction
  float speed;
  float heading; // 0 to 359 (360 is the same as 0)
} flight_t;

typedef struct position {
  float x;
  float y;
  float z;
} position_t;

#endif
