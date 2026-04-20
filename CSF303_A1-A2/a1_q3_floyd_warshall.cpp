#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const long long INF = 1e15;

void floydWarshall(int V, vector<vector<long long>>& dist) {

    // Core triple loop: try every vertex k as an intermediate point
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Negative cycle detection:
    // If dist[i][i] < 0 for any vertex i, a negative cycle passes through i
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected! Distance matrix is unreliable.\n";
            return;
        }
    }

    // Print the final distance matrix
    cout << "All-pairs shortest path matrix:\n";

    // Header row
    cout << setw(6) << " ";
    for (int j = 0; j < V; j++) cout << setw(6) << j;
    cout << "\n";

    // Separator
    cout << string(6 + V * 6, '-') << "\n";

    // Each row
    for (int i = 0; i < V; i++) {
        cout << setw(5) << i << " |";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) cout << setw(6) << "INF";
            else cout << setw(6) << dist[i][j];
        }
        cout << "\n";
    }
}

int main() {
    cout << "==========================================\n";
    cout << "  Assignment 1 - Q3: Floyd-Warshall\n";
    cout << "==========================================\n";
    cout << "Input format: enter V and E, then\n";
    cout << "E edges as (u v w). Vertices are 0-indexed.\n\n";

    int V, E;
    cin >> V >> E;

    // Initialise matrix: 0 on diagonal, INF elsewhere
    vector<vector<long long>> dist(V, vector<long long>(V, INF));
    for (int i = 0; i < V; i++) dist[i][i] = 0;

    for (int i = 0; i < E; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        // Keep the lighter edge if parallel edges exist
        dist[u][v] = min(dist[u][v], w);
    }

    floydWarshall(V, dist);

    return 0;
}