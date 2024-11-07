class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int m = mt.size();
        int n = mt[0].size();

        const int INF = 2e9;
        vector<vector<int>> dis(m, vector<int>(n, INF));
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        set<pair<int, pair<int, int>>> se;
        se.emplace(0, make_pair(0, 0));
        dis[0][0] = 0;
        while (!se.empty()) {
            auto now = *se.begin();
            se.erase(se.begin());
            int r = now.second.first, c = now.second.second;
            int ct = now.first;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (max(mt[nr][nc] + 1, ct + 1) < dis[nr][nc]) {
                    se.erase(make_pair(dis[nr][nc], make_pair(nr, nc)));
                    dis[nr][nc] = max(mt[nr][nc] + 1, ct + 1);
                    se.emplace(dis[nr][nc], make_pair(nr, nc));
                }
            }
        }
        return dis.back().back();
    }
};