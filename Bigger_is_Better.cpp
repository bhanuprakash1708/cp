#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        int maxVal = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        vector<int> freq(maxVal + 1, 0);
        for (int i = 0; i < N; i++) {
            freq[arr[i]]++;
        }
        int nonZeroOdd = 0;
        int totalZeroPairs = 0;
        int zerosFromInput = freq[0];
        for (int v = 1; v <= maxVal; v++) {
            if (freq[v] % 2 == 1)
                nonZeroOdd++;
            totalZeroPairs += freq[v] / 2;
        }
        int totalZeros = zerosFromInput + totalZeroPairs;
        int finalZeros = (totalZeros > 0) ? 1 : 0;
        int ans = nonZeroOdd + finalZeros;
        cout << ans << endl;
    }
    return 0;
}
