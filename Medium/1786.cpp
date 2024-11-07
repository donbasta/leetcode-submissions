class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[0] - 1].emplace_back(e[1] - 1, e[2]);
            adj[e[1] - 1].emplace_back(e[0] - 1, e[2]);
        } 
        const int INF = 2e9;
        vector<int> dis(n, INF);
        set<pair<int, int>> se;
        dis[n - 1] = 0;
        se.emplace(0, n - 1);
        while (!se.empty()) {
            auto now = *se.begin();
            se.erase(se.begin());
            int d = now.first, v = now.second;
            for (auto c : adj[v]) {
                if (dis[c.first] > d + c.second) {
                    se.erase(make_pair(dis[c.first], c.first));
                    dis[c.first] = d + c.second;
                    se.emplace(dis[c.first], c.first);
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << dis[i] << ' ';
        // }
        // cout << '\n';
        vector<vector<int>> from(n);
        vector<int> in(n);
        for (auto e : edges) {
            if (dis[e[0] - 1] > dis[e[1] - 1]) {
                // cout << e[0] - 1 << ' ' << e[1] - 1 << '\n';
                from[e[0] - 1].push_back(e[1] - 1);
                in[e[1] - 1]++;
            } else if (dis[e[0] - 1] < dis[e[1] - 1]) {
                from[e[1] - 1].push_back(e[0] - 1);
                in[e[0] - 1]++;
            }
        }
        vector<int> ret(n);
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                Q.push(i);
            }
        }
        const int MOD = 1e9 + 7;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            if (now == 0) ret[now]++;
            for (auto c : from[now]) {
                ret[c] = (ret[c] + ret[now]) % MOD;
                in[c]--;
                if (in[c] == 0) {
                    Q.push(c);
                }
            }
        }
        return ret[n - 1];   
    }
};