#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long, int>

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> price(N + 1);
    for (int i = 1; i <= N; i++) cin >> price[i];

    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = price[1];  // pay refuel at City 1
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [currCost, u] = pq.top();
        pq.pop();
        if (currCost != dist[u]) continue;
        for (auto [v, d] : adj[u]) {
            long long newCost = currCost + d + price[v];
            if (newCost < dist[v]) {
                dist[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }

    ofstream fout("valoria_output.txt");
    if (dist[N] == INF) fout << -1 << "\n";
    else fout << dist[N] << "\n";
    fout.close();

    return 0;
}
