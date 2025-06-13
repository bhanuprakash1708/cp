
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findCoolSubsequence(const vector<int>& A) {
    unordered_map<int, int> count;
    for (int num : A) {
        count[num]++;
        if (count[num] > 1) {
            return {num};
        }
    }
    return {};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        vector<int> coolSubsequence = findCoolSubsequence(A);
        if (!coolSubsequence.empty()) {
            cout << coolSubsequence.size() << endl;
            for (int num : coolSubsequence) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}