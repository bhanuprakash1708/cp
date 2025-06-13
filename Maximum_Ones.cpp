#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int compute(int N) {
    if (N == 1) return 1;
    long long res = 3;
    for (int i = 2; i < N; ++i) {
        res = (res * 2) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N == 1) cout << "1\n";
        else {
            long long ans = 3;
            for (int i = 2; i < N; ++i) {
                ans = (ans * 2) % MOD;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}