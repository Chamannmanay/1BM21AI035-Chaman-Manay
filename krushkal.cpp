#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;

    Edge(int source, int destination, int edgeWeight) : src(source), dest(destination), weight(edgeWeight) {}
};

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.emplace_back(src, dest, weight);
    }

    // Find set of an element (uses path compression technique)
    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    // Union of two sets (uses union by rank)
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    void kruskalsMST() {
        // Sort edges in non-decreasing order of their weights
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initialize each vertex as a separate set
        for (int i = 0; i < V; i++)
            parent[i] = i;

        vector<Edge> result;
        int totalWeight = 0;

        for (const Edge& edge : edges) {
            int srcRoot = find(parent, edge.src);
            int destRoot = find(parent, edge.dest);

            // If including this edge doesn't cause a cycle, add it to the result
            if (srcRoot != destRoot) {
                result.push_back(edge);
                totalWeight += edge.weight;
                unionSets(parent, rank, srcRoot, destRoot);
            }
        }

        cout << "Minimum Spanning Tree (MST) Edges:" << endl;
        for (const Edge& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }

        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    graph.kruskalsMST();

    return 0;
}
