class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 2e9;
        vector<int> dp(n, INF);
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : times) {
            adj[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        }
        set<pair<int, int>> se;
        dp[k - 1] = 0;
        se.emplace(0, k - 1);
        while (!se.empty()) {
            auto val = se.begin()->first, v = se.begin()->second;
            se.erase(se.begin());
            for (auto c : adj[v]) {
                if (dp[c.first] > c.second + val) {
                    se.erase(make_pair(dp[c.first], c.first));
                    dp[c.first] = c.second + val;
                    se.emplace(dp[c.first], c.first);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        if (ans == INF) return -1;
        return ans;
    }
};