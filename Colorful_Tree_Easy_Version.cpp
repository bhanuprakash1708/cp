#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> tree;
vector<int> distRed, distBlue, distGreen;

// BFS function to calculate distances from multiple sources
void bfs(const vector<int>& sources, vector<int>& dist) {
    queue<int> q;
    for (int src : sources) {
        q.push(src);
        dist[src] = 0;
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : tree[node]) {
            if (dist[neighbor] == INF) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; // Number of test cases
    cin >> T;
    
    while (T--) {
        int N; // Number of vertices
        cin >> N;
        
        // Initialize the tree and distance vectors
        tree.assign(N + 1, vector<int>());
        distRed.assign(N + 1, INF);
        distBlue.assign(N + 1, INF);
        distGreen.assign(N + 1, INF);
        
        // Read the edges
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // Select arbitrary vertices to start coloring
        // This is a simplified approach, you can try different combinations.
        vector<int> reds = {1}; // Assume 1st node is red
        vector<int> blues = {2}; // Assume 2nd node is blue
        vector<int> greens = {3}; // Assume 3rd node is green

        // Run BFS for each color
        bfs(reds, distRed);
        bfs(blues, distBlue);
        bfs(greens, distGreen);

        // Compute the minimum beauty for the entire tree
        long long minBeauty = 0;
        for (int u = 1; u <= N; u++) {
            // Score(u) = min distance to any vertex of different colors
            int score = distRed[u] + distBlue[u] + distGreen[u];
            minBeauty += score;
        }

        cout << minBeauty << "\n";

        // Clear the tree structure for the next test case
        tree.clear();
    }

    return 0;
}
