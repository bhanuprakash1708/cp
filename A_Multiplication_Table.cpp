#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is lexicographically larger than another
bool isLexicographicallyLarger(const string &P, const string &A) {
    return P > A;
}

void solve() {
    int N;
    string A;
    cin >> N >> A;
    
    string P = A;
    
    // Try to create a lexicographically larger string
    bool found = false;
    for (int i = N - 1; i >= 0; --i) {
        if (P[i] < 'z') {
            P[i]++;
            fill(P.begin() + i + 1, P.end(), 'a');
            if (isLexicographicallyLarger(P, A) && isLexicographicallyLarger(string(P.rbegin(), P.rend()), A)) {
                found = true;
                break;
            }
        }
    }
    
    if (found) cout << P << "\n";
    else cout << "-1\n";
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