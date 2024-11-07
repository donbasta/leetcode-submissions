class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> applesInSubtree(n);
        const function<void(int, int)> dfs = [&](int v, int par) -> void {
            int tmp = hasApple[v];
            for (auto e : adj[v]) {
                if (e == par) continue;
                dfs(e, v);
                tmp += applesInSubtree[e];
            }
            applesInSubtree[v] = tmp;
        };
        dfs(0, 0);
        int ans = 0;
        const function<void(int, int)> dfsWalk = [&](int v, int par) -> void {
            for (auto e : adj[v]) {
                if (e == par) continue;
                if (applesInSubtree[e] == 0) continue;
                ans++;
                dfsWalk(e, v);
                ans++;
            }
        };
        dfsWalk(0, 0);
        return ans;
    }
};