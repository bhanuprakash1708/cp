#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // Check for immediate solution for small strings
    if (n == 2) {
        if (s[0] != s[1]) {
            cout << "YES" << endl;
            cout << "1 2" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    // Traverse and find a segment where the counts of 'A' and 'B' are equal
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            cout << "YES" << endl;
            cout << i << " " << i + 1 << endl;
            return 0;
        }
    }

    // If no such segment is found
    cout << "NO" << endl;
    return 0;
}
