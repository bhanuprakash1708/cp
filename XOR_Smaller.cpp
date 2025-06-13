#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;  // Number of test cases
    while (T--) {
        int N;
        cin >> N;  // Size of the array
        vector<int> A(N);
        
        // Input the elements of the array
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        // Find the minimum element in the array
        int minValue = *min_element(A.begin(), A.end());

        // The number of valid X values is all integers from 1 up to minValue - 1
        cout << minValue - 1 << endl;
    }
    
    return 0;
}
