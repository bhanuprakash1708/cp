#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool can_reach(const vector<int>& h, int start, int target) {
    int n = h.size();
    vector<bool> visited(n, false);
    vector<int> q;
    q.push_back(start);
    visited[start] = true;

    for (int i = 0; i < q.size(); ++i) {
        int curr = q[i];
        if (curr == target) {
            return true;
        }

        if (curr > 0 && !visited[curr - 1]) {
            bool valid = true;
            for (int j = 0; j < q.size(); ++j) {
                if (h[curr - 1] == h[q[j]]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                q.push_back(curr - 1);
                visited[curr - 1] = true;
            }
        }

        if (curr < n - 1 && !visited[curr + 1]) {
            bool valid = true;
            for (int j = 0; j < q.size(); ++j) {
                if (h[curr + 1] == h[q[j]]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                q.push_back(curr + 1);
                visited[curr + 1] = true;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int friendships = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (can_reach(h, i, j) || can_reach(h, j, i)) {
                friendships++;
            } else {
                for (int k = 0; k < n; k++) {
                  if(i == k || j == k) continue;
                  if(can_reach(h,i,k) && can_reach(h,j,k)){
                      friendships++;
                      break;
                  }
                }
            }
        }
    }
    cout << friendships << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}