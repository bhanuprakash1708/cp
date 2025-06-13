#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N, M; // Number of donut types and customers
        cin >> N >> M;

        vector<int> A(N); // Donuts available of each type
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<int> B(M); // Donut types customers want
        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }

        int sad_count = 0; // Number of sad customers

        for (int i = 0; i < M; ++i) {
            int type = B[i] - 1; // Convert 1-based index to 0-based
            if (A[type] > 0) {
                A[type]--; // Satisfy the customer by reducing the stock
            } else {
                sad_count++; // Customer is sad
            }
        }

        cout << sad_count << endl; // Output result for this test case
    }

    return 0;
}
