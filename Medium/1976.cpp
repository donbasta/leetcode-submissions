class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto e : roads) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        set<pair<long long, int>> se;
        const long long INF = 1e18;
        long long dis[n];
        for (int i = 0; i < n; i++) dis[i] = INF;
        vector<int> par[n];
        dis[0] = 0;
        se.emplace(0, 0);
        while (!se.empty()) {
            long long val = se.begin()->first;
            int v = se.begin()->second;
            se.erase(se.begin());
            for (auto c : adj[v]) {
                if (dis[v] + c.second < dis[c.first]) {
                    par[c.first].clear();
                    par[c.first].push_back(v);
                    se.erase(make_pair(dis[c.first], c.first));
                    dis[c.first] = dis[v] + c.second;
                    se.emplace(dis[c.first], c.first);
                } else if (dis[v] + c.second == dis[c.first]) {
                    par[c.first].push_back(v);
                }
            }
        }
        int in[n];
        memset(in, 0, sizeof(n));
        vector<int> nx[n];
        for (int i = 0; i < n; i++) {
            in[i] = par[i].size();
            for (auto e : par[i]) {
                nx[e].push_back(i);
            }
        }
        const int MOD = 1e9 + 7;
        queue<int> Q;
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        Q.emplace(0);
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : nx[now]) {
                dp[c] = (dp[c] + dp[now]) % MOD;
                --in[c];
                if (in[c] == 0) {
                    Q.emplace(c);
                }
            }
        }
        return dp[n - 1];
    }
};