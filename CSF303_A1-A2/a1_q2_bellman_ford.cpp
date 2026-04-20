#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int src, vector<Edge>& edges) {
    // Step 1: Initialise all distances to infinity except the source
    vector<long long> dist(V, LLONG_MAX);
    dist[src] = 0;

    // Step 2: Relax all edges exactly V-1 times
    // After k iterations, shortest paths using at most k edges are correct.
    for (int i = 0; i < V - 1; i++) {
        bool updated = false;
        for (const Edge& e : edges) {
            if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        // Early exit optimisation: if nothing was updated, it is done
        if (!updated) break;
    }

    // Step 3: Negative cycle detection
    // If we can still relax an edge after V-1 iterations, a negative cycle exists
    for (const Edge& e : edges) {
        if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative weight cycle detected! Shortest paths are undefined.\n";
            return;
        }
    }

    // Step 4: Print results
    cout << "Shortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "  Vertex " << i << " : ";
        if (dist[i] == LLONG_MAX) cout << "UNREACHABLE";
        else cout << dist[i];
        cout << "\n";
    }
}

int main() {
    cout << "========================================\n";
    cout << "  Assignment 1 - Q2: Bellman-Ford\n";
    cout << "========================================\n";
    cout << "Input format: first enter V and E,\n";
    cout << "then E edges as (u v w), then source.\n\n";

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int src;
    cin >> src;

    bellmanFord(V, src, edges);
    return 0;
}