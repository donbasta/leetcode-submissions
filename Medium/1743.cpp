class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto e : adjacentPairs) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int cur = -1;
        for (auto e : adj) {
            if (e.second.size() == 1) {
                cur = e.first;
                break;
            }
        }
        vector<int> ret = {cur};
        int nxt = adj[cur][0];
        while (true) {
            ret.push_back(nxt);
            int tmp = INT_MIN;
            for (auto c : adj[nxt]) {
                if (c == cur) continue;
                tmp = c;
            }
            if (tmp == INT_MIN) break;
            cur = nxt;
            nxt = tmp;
        }
        return ret;
    }
};