#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> depth, size;

void dfs(int v, int p) {
    size[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
            size[v] += size[u];
        }
    }
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    int N;
    cin >> N;
    adj.resize(N + 1);
    depth.resize(N + 1);
    size.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    depth[1] = 0;
    dfs(1, -1);

    long long P = 0, Q = 1LL * N * (N + 1) / 2 % MOD;
    for (int i = 1; i <= N; ++i) {
        P = (P + 1LL * depth[i] * size[i] % MOD * (N - size[i] + 1) % MOD) % MOD;
    }

    int Q_inv = modInverse(Q, MOD);
    cout << P * Q_inv % MOD << endl;

    return 0;
}
