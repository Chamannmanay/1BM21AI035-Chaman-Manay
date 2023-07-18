#include <iostream>
#include <queue>
#include <limits>

const int MAX_VERTICES = 100;

class Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int v) : vertices(v) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int weight) {
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }

    int minKey(int key[], bool mstSet[]) {
        int min = std::numeric_limits<int>::max();
        int min_index = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }

    void primMST() {
        int parent[MAX_VERTICES];
        int key[MAX_VERTICES];
        bool mstSet[MAX_VERTICES];

        for (int i = 0; i < vertices; ++i) {
            key[i] = std::numeric_limits<int>::max();
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; ++count) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < vertices; ++v) {
                if (adjacencyMatrix[u][v] && !mstSet[v] && adjacencyMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjacencyMatrix[u][v];
                }
            }
        }

        std::cout << "Edge\tWeight\n";
        for (int v = 1; v < vertices; ++v) {
            std::cout << parent[v] << " - " << v << "\t" << adjacencyMatrix[v][parent[v]] << "\n";
        }
    }
};

int main() {
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    Graph graph(numVertices);

    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        std::cout << "Enter edge " << i + 1 << " source, destination, and weight: ";
        std::cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    std::cout << "Minimum Spanning Tree:\n";
    graph.primMST();

    return 0;
}
