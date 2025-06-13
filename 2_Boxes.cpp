#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> X(n), Y(n);
        
        // Read the original sequence X
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        // Read the final sequence Y
        for (int i = 0; i < n; i++) {
            cin >> Y[i];
        }
        
        int validPivot = -1;
        
        // Try every candidate pivot index (0-based, output as 1-based)
        for (int i = 0; i < n; i++) {
            int pivot = X[i];
            vector<pair<int, int>> pairs;
            
            // Create list L of pairs (|X[j]-pivot|, X[j])
            for (int j = 0; j < n; j++) {
                pairs.push_back({abs(X[j] - pivot), X[j]});
            }
            
            // Sort the pairs by increasing distance, then by value
            sort(pairs.begin(), pairs.end());

            // Check if the sorted values match Y
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (pairs[j].second != Y[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                validPivot = i + 1;
                break;
            }
        }
        
        cout << validPivot << endl;
    }
    
    return 0;
