#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        // Frequency map to count frogs in each bucket
        unordered_map<int, int> bucket_count;
        for (int i = 0; i < N; i++) {
            bucket_count[A[i]]++;
        }

        // Find the maximum count of frogs in a single bucket
        int max_frogs = 0;
        for (auto &entry : bucket_count) {
            max_frogs = max(max_frogs, entry.second);
        }

        cout << max_frogs << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
