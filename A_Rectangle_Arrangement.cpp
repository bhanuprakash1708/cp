#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculatePerimeter(vector<pair<int, int>>& stamps) {
    int maxWidth = 0;
    int maxHeight = 0;
    int totalPerimeter = 0;

    for (auto& stamp : stamps) {
        maxWidth = max(maxWidth, stamp.first);
        maxHeight = max(maxHeight, stamp.second);
        totalPerimeter += 2 * (stamp.first + stamp.second);
    }

    return min(totalPerimeter, 2 * (maxWidth + maxHeight));
}

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int numStamps;
        cin >> numStamps;

        vector<pair<int, int>> stamps(numStamps);
        for (auto& stamp : stamps) {
            cin >> stamp.first >> stamp.second;
        }

        int result = calculatePerimeter(stamps);
        cout << result << endl;
    }

    return 0;
}
