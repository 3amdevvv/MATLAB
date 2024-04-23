#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define INF 9999999

int main() {
    int V; // number of vertices in graph
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // create a 2d array for adjacency matrix to represent the graph
    int G[V][V];

    // take input for adjacency matrix
    printf("Enter the adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    int selected[V];
    memset(selected, false, sizeof(selected));
    selected[0] = true;

    int no_edge = 0;
    int min_cost = 0;

    printf("Edges in MST:\n");

    while (no_edge < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);
        min_cost += G[x][y];
        selected[y] = true;
        no_edge++;
    }

    printf("Minimum cost of MST: %d\n", min_cost);

    return 0;
}
//vertices put 4 
// 0 10 20 0
// 10 0 30 5
// 20 30 0 15
// 0 5 15 0