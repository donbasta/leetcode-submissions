class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int nn = roads.size();
        int n = nn + 1;
        vector<vector<int>> adj(n);
        for (auto e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        vector<int> from(n);
        const function<void(int, int)> dfs = [&](int v, int par) -> void {
            from[v] = 1;
            for (auto c : adj[v]) {
                if (c == par) continue;
                dfs(c, v);
                ans += (from[c] + seats - 1) / seats;
                from[v] += from[c];
            }
        };
        dfs(0, 0);
        return ans;
    }
};