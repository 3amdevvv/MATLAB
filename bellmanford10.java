import java.util.Scanner;

class bellmanford10 {
  
    class Edge {
        int src, dest, weight;
        Edge() { src = dest = weight = 0; }
    };

    int V, E;
    Edge edge[];

    bellmanford10(int v, int e)
    {
        V = v;
        E = e;
        edge = new Edge[e];
        for (int i = 0; i < e; ++i)
            edge[i] = new Edge();
    }

    void BellmanFord(bellmanford10 graph, int src)
    {
        int V = graph.V, E = graph.E;
        int dist[] = new int[V];
        int pred[] = new int[V];

        // Step 1: Initialize distances and predecessors
        for (int i = 0; i < V; ++i) {
            dist[i] = Integer.MAX_VALUE;
            pred[i] = -1;
        }
        dist[src] = 0;

        // Step 2: Relax edges |V| - 1 times
        for (int i = 1; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = graph.edge[j].src;
                int v = graph.edge[j].dest;
                int weight = graph.edge[j].weight;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pred[v] = u;
                }
            }
        }

        // Step 3: Check for negative-weight cycles
        for (int j = 0; j < E; ++j) {
            int u = graph.edge[j].src;
            int v = graph.edge[j].dest;
            int weight = graph.edge[j].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                System.out.println("Graph contains negative weight cycle");
                return;
            }
        }

        // Print D and Pi matrices
        System.out.println("Distance Matrix:");
        for (int i = 0; i < V; ++i) {
            System.out.print(dist[i] + " ");
        }
        System.out.println("\nPredecessor Matrix:");
        for (int i = 0; i < V; ++i) {
            System.out.print(pred[i] + " ");
        }
        System.out.println();

        // Print path between every pair of vertices
        for (int i = 0; i < V; ++i) {
            if (dist[i] != Integer.MAX_VALUE) {
                System.out.print("Path from " + src + " to " + i + ": ");
                printPath(pred, i);
                System.out.println();
            }
        }
    }

    void printPath(int[] pred, int j)
    {
        if (j == -1) {
            return;
        }
        printPath(pred, pred[j]);
        System.out.print(j + " ");
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of vertices:");
        int V = scanner.nextInt();

        System.out.println("Enter the number of edges:");
        int E = scanner.nextInt();

        bellmanford10 graph = new bellmanford10(V, E);

        for (int i = 0; i < E; i++) {
            System.out.println("Enter source, destination, and weight for edge " + (i + 1) + ":");
            graph.edge[i].src = scanner.nextInt();
            graph.edge[i].dest = scanner.nextInt();
            graph.edge[i].weight = scanner.nextInt();
        }

        System.out.println("Enter the source vertex:");
        int src = scanner.nextInt();

        graph.BellmanFord(graph, src);
        
        scanner.close();
    }
}


// Enter the number of vertices:
// 5
// Enter the number of edges:
// 8
// Enter source, destination, and weight for edge 1:
// 0 1 -1
// Enter source, destination, and weight for edge 2:
// 0 2 4
// Enter source, destination, and weight for edge 3:
// 1 2 3
// Enter source, destination, and weight for edge 4:
// 1 3 2
// Enter source, destination, and weight for edge 5:
// 1 4 2
// Enter source, destination, and weight for edge 6:
// 3 2 5
// Enter source, destination, and weight for edge 7:
// 3 1 1
// Enter source, destination, and weight for edge 8:
// 4 3 -3
// Enter the source vertex:
// 0

// Distance Matrix:
// 0 -1 2 -1 1
// Predecessor Matrix:
// -1 0 1 4 1
// Path from 0 to 0: 0
// Path from 0 to 1: 0 1
// Path from 0 to 2: 0 1 2
// Path from 0 to 3: 0 1 4 3
// Path from 0 to 4: 0 1 4