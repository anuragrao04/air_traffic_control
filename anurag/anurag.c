#include "anurag.h"
#include <stdio.h>
#define INF 99999

int minDistance(int dist[], int sptSet[], int num_places) {
  int min = INF, min_index;
  for (int v = 0; v < num_places; v++)
    if (sptSet[v] == 0 && dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}

void printSolution(int dist[], int num_places, int src, int destination) {
  printf("The shortest distance from node %d to node %d is: %d\n", src,
         destination, dist[destination]);
}

void dijkstras_fastest_path(int graph[MAX_SIZE][MAX_SIZE], int num_places,
                            int source, int destination) {
  int dist[num_places];   // The output array. dist[i] will hold the shortest
                          // distance from src to i
  int sptSet[num_places]; // sptSet[i] will be true if vertex i is included in
                          // shortest path tree or shortest distance from src to
                          // i is finalized
  for (int i = 0; i < num_places; i++)
    dist[i] = INF, sptSet[i] = 0;
  dist[source] = 0;
  for (int count = 0; count < num_places - 1; count++) {
    int u = minDistance(dist, sptSet, num_places);
    sptSet[u] = 1;
    for (int v = 0; v < num_places; v++)
      if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
  printSolution(dist, num_places, source, destination);
}
