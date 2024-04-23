#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int comparator(const void* p1, const void* p2) {
    return (*(int (*)[3])p1)[2] - (*(int (*)[3])p2)[2];
}

int findParent(int parent[], int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = findParent(parent, parent[u]);
}

void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

void kruskalAlgo(int n, int edge[][3]) {
    qsort(edge, n, sizeof(edge[0]), comparator);

    int parent[n], rank[n], minCost = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Following are the edges in the constructed MST\n");
    for (int i = 0; i < n; i++) {
        int u = edge[i][0], v = edge[i][1], wt = edge[i][2];
        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(u, v, parent, rank);
            minCost += wt;
            printf("%d -- %d == %d\n", u, v, wt);
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    int n;
    printf("Enter the number of edges: ");
    scanf("%d", &n);

    int edge[n][3];
    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    kruskalAlgo(n, edge);
    return 0;
}

// Enter the number of edges: 5
// Enter the edges (source, destination, weight):
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4
