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

void printPath(int parent[], int j) {
  if (j == -1)
    return;
  printPath(parent, parent[j]);
  printf("-> %d ", j);
}

void printSolution(int dist[], int source, int destination, int parent[]) {
  printf("shortest path: ");
  printPath(parent, destination);
  printf("\n");
}

void dijkstras_fastest_path(int graph[MAX_SIZE][MAX_SIZE], int num_places,
                            int source, int destination) {
  int dist[num_places];
  int sptSet[num_places];
  int parent[num_places];

  for (int i = 0; i < num_places; i++) {
    parent[source] = -1;
    dist[i] = INF;
    sptSet[i] = 0;
  }
  dist[source] = 0;

  for (int count = 0; count < num_places - 1; count++) {
    int u = minDistance(dist, sptSet, num_places);
    sptSet[u] = 1;
    for (int v = 0; v < num_places; v++)
      if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
        parent[v] = u;
        dist[v] = dist[u] + graph[u][v];
      }
  }
  printSolution(dist, source, destination, parent);
}
