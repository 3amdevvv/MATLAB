#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int pred[]) {
    printf("Vertex \t\t Distance from Source \t\t Predecessor\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d \t\t\t\t\t %d\n", i, dist[i], pred[i]);
}

void printPath(int pred[], int j) {
    if (pred[j] == -1) {
        printf("%d ", j);
        return;
    }

    printPath(pred, pred[j]);
    printf("%d ", j);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int pred[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        pred[i] = -1;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }

    printSolution(dist, pred);
    printf("\nShortest paths from source vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("Path from %d to %d: ", src, i);
        printPath(pred, i);
        printf("\n");
    }
}

int main() {
    int graph[V][V];
    int src;

    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex (0-%d): ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}

// Enter the adjacency matrix (9 x 9):
// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0
// Enter the source vertex (0-8): 0

// Vertex 		 Distance from Source 			 Predecessor
// 0 					 0 								 -1
// 1 					 4 								 0
// 2 					 12 								 5
// 3 					 19 								 2
// 4 					 21 								 6
// 5 					 11 								 2
// 6 					 9 								 7
// 7 					 8 								 0
// 8 					 14 								 2

// Shortest paths from source vertex 0:
// Path from 0 to 0: 0
// Path from 0 to 1: 0 1
// Path from 0 to 2: 0 7 6 5 2
// Path from 0 to 3: 0 1 2 3
// Path from 0 to 4: 0 7 6 5 4
// Path from 0 to 5: 0 7 6 5
// Path from 0 to 6: 0 7 6
// Path from 0 to 7: 0 7
// Path from 0 to 8: 0 7 8