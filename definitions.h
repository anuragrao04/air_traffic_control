#ifndef DEFINITIONS
#define DEFINITIONS
#define MAX_SIZE 100
typedef struct flight {
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
