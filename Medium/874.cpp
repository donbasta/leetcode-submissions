class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int cur = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int cx = 0, cy = 0;
        set<pair<int, int>> se;
        for (auto c : obstacles) {
            se.emplace(c[0], c[1]);
        }
        int ans = 0;
        for (auto c : commands) {
            if (c == -2) {
                cur = (cur + 3) % 4;
            } else if (c == -1) {
                cur = (cur + 1) % 4;
            } else {
                for (int i = 0; i < c; i++) {
                    int nx = cx + dx[cur], ny = cy + dy[cur];
                    if (se.count(make_pair(nx, ny))) break;
                    cx = nx, cy = ny;
                    ans = max(ans, cx * cx + cy * cy);
                }
            }
        }
        return ans;
    }
};