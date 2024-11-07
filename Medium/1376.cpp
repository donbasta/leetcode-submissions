class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            adj[i].push_back(manager[i]);
            adj[manager[i]].push_back(i);
        }
        
        int ans = 0;
        const function<void(int, int, int)> dfs = [&](int v, int p, int t) -> void {
            ans = max(ans, t);
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v, t + informTime[v]);
            }
        };

        dfs(headID, headID, 0);
        return ans;
    }
};