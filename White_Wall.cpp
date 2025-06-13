#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
void solve() {
    int M, K;
    cin >> M >> K;
    string S;
    cin >> S;
 
    vector<int> prefix(M + 1, 0);
    for (int i = 1; i <= M; i++) {
        prefix[i] = prefix[i - 1] + (S[i - 1] == 'S' ? 1 : 0);
    }
 
    int min_N = 0;
    if (M >= 2) {
        for (int t = 1; t < M; t++) {
            int temp = K - prefix[t] + t;
            if (temp > min_N) {
                min_N = temp;
            }
        }
    } else {
        min_N = M;
    }
 
    int max_N_candidate = M + K - prefix[M] - 1;
    int N = (max_N_candidate >= max(min_N, M)) ? max_N_candidate : M;
 
    cout << N << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}