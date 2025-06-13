#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        
        // Read the three binary strings.
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        
        // Count the number of '1's in each string.
        vector<int> a(3, 0);
        for (int i = 0; i < N; i++) {
            if (s1[i] == '1') a[0]++;
            if (s2[i] == '1') a[1]++;
            if (s3[i] == '1') a[2]++;
        }
        int totalOnes = a[0] + a[1] + a[2];
        
        // Check if it's possible.
        if (totalOnes == 0 || totalOnes == 3 * N) {
            // Already uniform.
            cout << "0\n";
        } else if (totalOnes == N) {
            // Exactly one string will be ones-target.
            // Choose the string with the maximum number of ones to minimize the deficit.
            int maxOnes = max({a[0], a[1], a[2]});
            cout << (N - maxOnes) << "\n";
        } else if (totalOnes == 2 * N) {
            // Exactly two strings will be ones-target.
            // The minimum operations equal the number of ones in the string with the smallest count.
            int minOnes = min({a[0], a[1], a[2]});
            cout << minOnes << "\n";
        } else {
            // Not possible to redistribute ones to get all strings uniform.
            cout << "-1\n";
        }
    }
    return 0;
}

