#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int MOD = 1000000007;

// Function to compute modular exponentiation
long long mod_exp(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;
        vector<int> stones(N);
        for (int i = 0; i < N; i++) {
            cin >> stones[i];
        }
        int xor_sum = accumulate(stones.begin(), stones.end(), 0, [](int a, int b) { return a ^ b; });
        long long P = (xor_sum != 0) ? D / 2 + 1 : D / 2;
        long long Q = D;
        long long Q_inv = mod_exp(Q, MOD - 2, MOD);
        long long result = (P * Q_inv) % MOD;
        
        cout << result << endl;
    }
    
    return 0;
}
