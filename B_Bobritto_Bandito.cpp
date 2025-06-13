#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        
        vector<int> p(2 * n + 1, 0); // 1-based indexing
        vector<bool> found(2 * n + 1, false);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = i + j + 1;
                if (p[s] == 0) {
                    p[s] = grid[i][j];
                    found[grid[i][j]] = true;
                }
            }
        }
        
        // Find the missing number for p[1]
        for (int num = 1; num <= 2 * n; ++num) {
            if (!found[num]) {
                p[1] = num;
                break;
            }
        }
        
        // Output the permutation from p[1] to p[2n]
        for (int i = 1; i <= 2 * n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}