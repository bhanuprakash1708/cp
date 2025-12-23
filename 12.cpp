#include <bits/stdc++.h>
using namespace std;

// We'll represent each edge as a pair (destination, distance)
struct Edge {
    int to;
    int dist;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Fuel price for each city (1-indexed)
    vector<int> price(N + 1);
    for (int i = 1; i <= N; i++) cin >> price[i];

    // Build adjacency list
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    const long long INF = 1e18;
    vector<long long> dist(N + 1, INF);

    // Min-heap priority queue: (cost_so_far, city)
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<>> pq;

    // Start from city 1
    dist[1] = price[1];
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();
        long long cost = top.first;
        int u = top.second;

        if (cost > dist[u]) continue;

        // For every road (u -> v)
        for (auto &edge : graph[u]) {
            int v = edge.to;
            long long newCost = cost + edge.dist + price[v];
            if (newCost < dist[v]) {
                dist[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }

    if (dist[N] == INF)
        cout << -1 << "\n";
    else
        cout << dist[N] << "\n";

    return 0;
}