class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int, int>> Q;
        Q.emplace(0, 1);
        int MX = max(2005, a * b + 100 + x);
        // int MX = 2005;

        // vector<vector<int>> ve(MX, vector<int>(2, -1));
        int ve[MX][2];
        memset(ve, -1, sizeof(ve));
        ve[0][1] = 0;

        vector<bool> forbid(MX);
        for (auto f : forbidden) forbid[f] = true;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            int pos = now.first, prev = now.second;
            if (prev == 0) {
                if ((pos + a < MX) && !forbid[pos + a] && ve[pos + a][1] == -1) {
                    ve[pos + a][1] = ve[pos][prev] + 1;
                    Q.emplace(pos + a, 1);
                }
            } else if (prev == 1) {
                if ((pos + a < MX) && !forbid[pos + a] && ve[pos + a][1] == -1) {
                    ve[pos + a][1] = ve[pos][prev] + 1;
                    Q.emplace(pos + a, 1);
                }
                if ((pos - b >= 0) && !forbid[pos - b] && ve[pos - b][0] == -1) {
                    ve[pos - b][0] = ve[pos][prev] + 1;
                    Q.emplace(pos - b, 0);
                }
            }
        }
        int ans = INT_MAX;
        if (ve[x][1] != -1) ans = min(ans, ve[x][1]);
        if (ve[x][0] != -1) ans = min(ans, ve[x][0]);
        if (ans == INT_MAX) ans = -1;
        return ans;
    }
};