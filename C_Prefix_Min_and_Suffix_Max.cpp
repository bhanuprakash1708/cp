// b code for u guys 
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
//https://t.me/coderhelpp
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1);a
        vector<bool> online(c + 1, true);b
        unordered_map<int, set<int>> gridOnlineStations;g
        for (int i = 1; i <= c; ++i)
            parent[i] = i;
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa != pb)
                parent[pa] = pb;
        };
        for (auto& conn : connections) {
            unite(conn[0], conn[1]);
        }
        for (int i = 1; i <= c; ++i)
            find(i);
        for (int i = 1; i <= c; ++i) {
            int root = parent[i];
            gridOnlineStations[root].insert(i);
        }
//https://t.me/coderhelpp
        vector<int> result;
        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = find(x);
            if (type == 1) {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (gridOnlineStations[root].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*gridOnlineStations[root].begin());
                    }
                }//https://t.me/coderhelpp
            } else if (type == 2) {
                if (online[x]) {
                    gridOnlineStations[root].erase(x);
                    online[x] = false;}}}  return result;
    }
};//https://t.me/coderhelpp
©leetcode