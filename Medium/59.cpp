class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int x = 0, y = 0;
        vector<pair<int, int>> dir = {
            make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)
        };
        int cur = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            int nx = x + dir[cur].first, ny = y + dir[cur].second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                cur = (cur + 1) % 4;
            } else if (ans[nx][ny] != -1) {
                cur = (cur + 1) % 4;
            }
            x = x + dir[cur].first, y = y + dir[cur].second;
        }
        return ans;
    }
};