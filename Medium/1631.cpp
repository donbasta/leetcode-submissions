class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>> adj[m * n];
        pair<int, int> dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = i * n + j;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k].first;
                    int nj = j + dir[k].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    int ncur = ni * n + nj;
                    int dis = abs(heights[i][j] - heights[ni][nj]);
                    adj[cur].emplace_back(ncur, dis);
                }
            }
        }
        set<pair<int, int>> se;
        const int INF = 2e9;
        int dis[m * n];
        for (int i = 0; i < m * n; i++) dis[i] = INF;
        dis[0] = 0;
        se.insert(make_pair(0, 0));
        while (!se.empty()) {
            auto now = se.begin();
            int v = now->second;
            se.erase(now);
            for (auto c : adj[v]) {
                if (max(dis[v], c.second) < dis[c.first]) {
                    se.erase(make_pair(dis[c.first], c.first));
                    dis[c.first] = max(dis[v], c.second);
                    se.emplace(dis[c.first], c.first);
                }
            }
        }
        return dis[m * n - 1];
    }
};