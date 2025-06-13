#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Function to calculate the number of derangements
int countDerangements(int n) {
    // Base cases
    if (n == 0) return 1;
    if (n == 1) return 0;

    // Create an array to store derangements for all values up to n
    int dp[n + 1];

    // Initialize the base cases
    dp[0] = 1; // D(0)
    dp[1] = 0; // D(1)

    // Fill the dp array using the recursive relation
    for (int i = 2; i <= n; i++) {
        dp[i] = (1LL * (i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    // Input the number of color packets
    cin >> n;

    // Output the number of derangements modulo 1000000007
    cout << countDerangements(n) << endl;

    return 0;
}
