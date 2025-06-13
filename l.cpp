#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Function to calculate the number of distinct common elements between two arrays
void dfs(int n, vector<bool>& v, vector<vector<int>>& g) {
    v[n] = true;
    for (auto i : g[n]) {
        if (!v[i]) {
            dfs(i, v, g);
        }
    }
}

// Function to calculate the intersection size between two sets (properties)
int ist(vector<int>& a, vector<int>& b) {
    int r = 0;
    unordered_set<int> setA(a.begin(), a.end()); // Use unordered_set for faster lookup
    for (int num : b) {
        if (setA.count(num)) {  // Count common elements
            r++;
        }
    }
    return r;
}

int numberOfComponents(vector<vector<int>>& properties, int k) {
    int n = properties.size(), c = 0;
    vector<vector<int>> g(n);
    
    // Build the graph based on the intersection condition
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ist(properties[i], properties[j]) >= k) {
                g[i].push_back(j);
                g[j].push_back(i); // Add both directions for undirected graph
            }
        }
    }
    
    vector<bool> v(n, false);
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            dfs(i, v, g);
            c++;  // Count a new connected component
        }
    }
    
    return c;  // Return the number of connected components
}

int main() {
    // Test Case 1
    vector<vector<int>> properties1 = {{1,2}, {1,1}, {3,4}, {4,5}, {5,6}, {7,7}};
    int k1 = 1;
    cout << "Test Case 1: " << countConnectedComponents(properties1, k1) << endl; // Expected Output: 3

    // Test Case 2
    vector<vector<int>> properties2 = {{1,2,3}, {2,3,4}, {4,3,5}};
    int k2 = 2;
    cout << "Test Case 2: " << countConnectedComponents(properties2, k2) << endl; // Expected Output: 1

    // Test Case 3
    vector<vector<int>> properties3 = {{1,1}, {1,1}};
    int k3 = 2;
    cout << "Test Case 3: " << countConnectedComponents(properties3, k3) << endl; // Expected Output: 2

    return 0;
}
