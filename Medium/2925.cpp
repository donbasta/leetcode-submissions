class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long sum[n], dp[n];
        const function<void(int, int)> dfs = [&](int v, int p) {
            sum[v] = values[v];
            int cnt_child = 0;
            for (auto c : adj[v]) {
                if (c == p) continue;
                cnt_child++;
                dfs(c, v);
                sum[v] += sum[c];
            }
            if (cnt_child == 0) {
                dp[v] = 0;
            } else {
                long long A = sum[v] - values[v];
                long long B = values[v];
                for (auto c : adj[v]) {
                    if (c == p) continue;
                    B += dp[c];
                }
                dp[v] = max(A, B);
            }
        };
        dfs(0, 0);
        return dp[0];
    }
};