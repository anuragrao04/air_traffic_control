#include "anikethan/anikethan.h"
#include "anurag/anurag.h"
#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#define INF 99999

int main(int argc, char *argv[]) {

  printf("Taking input from input.txt\n");
  FILE *input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    printf("Error opening input file\n");
    return EXIT_FAILURE;
  }

  // first we take input forj a graph that represents the map. This can include
  // places and waypoints. Both are treated the same. So we are not taking input
  // for waypoints separately

  // First, we take input for the number of places
  int num_places;
  fscanf(input_file, "%d", &num_places);
  fscanf(input_file, "\n");

  // Then we take input for the graph for these places. This is a square matrix.
  int graph[MAX_SIZE][MAX_SIZE];

  while (1) {
    int i, j, weight; // the weight here will be a number representing the sum
                      // of parameters like distance, weather, etc.
    fscanf(input_file, "%d %d %d", &i, &j, &weight);
    fscanf(input_file, "\n");
    if (i == -1 && j == -1 && weight == -1) {
      break;
    }
    graph[i][j] = weight;
    // planes can fly in both directions so assuming that all paths are
    // undirected
    graph[j][i] = weight;
  }

  // Then we take input for the number of flights
  int num_flights;
  fscanf(input_file, "%d", &num_flights);
  fscanf(input_file, "\n");

  // every flight has an x, y and z coordinate along with it's speed and
  // heading. We take input for these

  flight_t *flights[MAX_SIZE];

  for (int i = 0; i < num_flights; i++) {
    flights[i] = malloc(sizeof(flight_t));
    flights[i]->id = i;
    fscanf(input_file, "%f %f %f %f %f", &flights[i]->x, &flights[i]->y,
           &flights[i]->z, &flights[i]->speed, &flights[i]->heading);
    fscanf(input_file, "\n");
  }

  // Now we have display the options available for our program

  while (1) {
    printf("\n\n1. Find Collisions\n2. Find Fastest Path\n0. Exit\n\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 0:
      printf("Exiting...\n");
      return EXIT_SUCCESS;
      break;

    case 1:
      printf("Finding collisions...\n");
      collision_avoidance(flights, num_flights);
      break;

    case 2:
      printf("Enter source and destination: ");
      int source, destination;
      scanf("%d %d", &source, &destination);
      printf("Finding fastest path...\n");
      dijkstras_fastest_path(graph, num_places, source, destination);
      break;
    }
  }
  return EXIT_SUCCESS;
}
