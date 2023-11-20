#include <stdio.h>

typedef struct flight {
  // current x y z prositions
  float x;
  float y;
  float z;
  // current speed and direction
  float speed;
  float heading; // 0 to 359 (360 is the same as 0)
} flight_t;

void collision_avoidance(flight_t *flights[], int num_flights){
    
}
#include <stdio.h>
#include <math.h>

// Structure to represent an aircraft
typedef struct {
    double x, y, z; // Position
} Aircraft;

// Function to calculate the distance between two aircraft
double calculateDistance(Aircraft a, Aircraft b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

// Function to check for a collision between two aircraft
int checkCollision(Aircraft a, Aircraft b) {
    double distance = calculateDistance(a, b);
    // Assuming a simple collision condition (e.g., a fixed separation distance)
    double separationDistance = 1000.0; // Adjust as needed
    return distance < separationDistance;
}

// Function to resolve a collision by adjusting the positions of two aircraft
void resolveCollision(Aircraft *a, Aircraft *b) {
    // Implement your collision resolution strategy here
    // For simplicity, let's assume a basic resolution of moving one aircraft away
    a->x += 500.0; // Move aircraft 'a' 500 units away
}

int main() {
    // Example usage with an array of aircraft
    Aircraft aircraftArray[3] = {
        {0.0, 0.0, 1000.0},
        {10.0, 0.0, 1000.0},
        {20.0, 0.0, 1000.0}
    };

    // Check for collisions among aircraft
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (checkCollision(aircraftArray[i], aircraftArray[j])) {
                printf("Collision detected between aircraft %d and %d!\n", i + 1, j + 1);
                // Resolve collision
                resolveCollision(&aircraftArray[i], &aircraftArray[j]);
                printf("Collision resolved. New position of aircraft%d: %.2f, %.2f, %.2f\n", i + 1,
                       aircraftArray[i].x, aircraftArray[i].y, aircraftArray[i].z);
            }
        }
    }

    return 0;
}
