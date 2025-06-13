
#include <bits/stdc++.h>

using namespace std;

bool can_sort(int n, vector<int>& a, int b_val) {
    if (n == 0) return true;
    
    int prev = min(a[0], b_val - a[0]);
    
    for (int i = 1; i < n; i++) {
        int current = a[i];
        int option1 = current;
        int option2 = b_val - current;
        vector<int> valid_options;
        
        if (option1 >= prev) valid_options.push_back(option1);
        if (option2 >= prev) valid_options.push_back(option2);
        
        if (valid_options.empty()) return false;
        
        prev = *min_element(valid_options.begin(), valid_options.end());
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        int b_val = b[0]; // The first value of b is used
        
        if (can_sort(n, a, b_val)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}