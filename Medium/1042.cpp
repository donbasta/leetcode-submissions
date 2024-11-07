class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (auto p : paths) {
            adj[p[0] - 1].push_back(p[1] - 1);
            adj[p[1] - 1].push_back(p[0] - 1);
        }
        vector<int> val(n, -1);
        for (int i = 0; i < n; i++) {
            vector<bool> tmp(5);
            for (auto c : adj[i]) {
                if (val[c] == -1) continue;
                else {
                    tmp[val[c]] = true;
                }
            }
            int pick = -1;
            for (int j = 1; j <= 4; j++) {
                if (!tmp[j]) {
                    pick = j;
                    break;
                }
            }
            assert (pick != -1);
            val[i] = pick;
        }
        return val;
    }
};