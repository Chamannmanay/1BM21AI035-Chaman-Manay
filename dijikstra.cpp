#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    vector<int> dijkstra(int start) {
        vector<int> distances(V, numeric_limits<int>::max());
        vector<bool> visited(V, false);

        // Priority queue to get the vertex with minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Set distance of start vertex to 0 and push it to the priority queue
        distances[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            // Visit all neighboring vertices of u
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If v is not visited and the distance through u is shorter
                if (!visited[v] && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.push(make_pair(distances[v], v));
                }
            }
        }

        return distances;
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
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<int> distances = graph.dijkstra(startVertex);

    cout << "Shortest distances from vertex " << startVertex << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
