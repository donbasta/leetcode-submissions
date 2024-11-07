class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int ans = 0;
        vector<bool> res(n);
        for (auto r : restricted) res[r] = true;
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        function<void(int, int)> dfs = [&](int v, int p) -> void {
            ans++;
            for (auto c : adj[v]) {
                if (c == p) continue;
                if (!res[c]) dfs(c, v);
            }
        };
        dfs(0, 0);
        return ans;
    }
};