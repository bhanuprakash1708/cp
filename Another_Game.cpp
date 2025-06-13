#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinK(vector<int>& P, int N) {
    vector<int> sortedP = P;
    sort(sortedP.begin(), sortedP.end());
    int K = 0;
    for (int i = 0; i < N; ++i) {
        K = max(K, sortedP[i] + sortedP[(i + 1) % N]);
    }
    return K;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        cout << findMinK(P, N) << endl;
    }
    return 0;
}
