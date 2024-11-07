class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const int INF = 1e9;
        vector<vector<int>> D(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) D[i][i] = 0;
        int ans = 0;
        for (auto r : roads) {
            D[r[0]][r[1]] = min(r[2], D[r[0]][r[1]]);
            D[r[1]][r[0]] = min(r[2], D[r[1]][r[0]]);
        }
        for (int i = 0; i < (1 << n); i++) {
            vector<vector<int>> dis(n, vector<int>(n, INF));
            vector<bool> off(n);
            for (int j = 0; j < n; j++) off[j] = !((i >> j) & 1);
            for (int j = 0; j < n; j++) {
                if (off[j]) continue;
                for (int k = 0; k < n; k++) {
                    if (off[k]) continue;
                    dis[j][k] = D[j][k];
                }
            }
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    for (int r = 0; r < n; r++) {
                        dis[q][r] = min(dis[q][r], dis[q][p] + dis[p][r]);
                    }
                }
            }
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (off[j]) continue;
                for (int k = 0; k < n; k++) {
                    if (off[k]) continue;
                    if (dis[j][k] > maxDistance) {
                        ok = false;
                        break;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};