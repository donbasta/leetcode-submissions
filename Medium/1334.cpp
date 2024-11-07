class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        int ans = n, mn = n;
        const int INF = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> dis(n, INF);
            dis[i] = 0;
            set<pair<int, int>> se;
            se.emplace(0, i);
            while (!se.empty()) {
                auto now = *se.begin();
                se.erase(se.begin());
                for (auto c : adj[now.second]) {
                    if (now.first + c.second < dis[c.first]) {
                        se.erase(make_pair(dis[c.first], c.first));
                        dis[c.first] = now.first + c.second;
                        se.emplace(dis[c.first], c.first);
                    }
                }
            }
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                tmp += dis[j] <= distanceThreshold;
            }
            if (tmp < mn) {
                mn = tmp;
                ans = i;
            }
        }
        return ans;
    }
};