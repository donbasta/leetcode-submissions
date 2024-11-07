class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -10);
        for (int i = 0; i < n; i++) {
            int cur = i;
            for (int j = 0; j < m; j++) {
                if (grid[j][cur] == 1) {
                    if (cur + 1 == n) {
                        ans[i] = -1;
                        break;
                    } else if (cur + 1 < n && grid[j][cur + 1] == -1) {
                        ans[i] = -1;
                        break;
                    } else {
                        cur++;
                    }
                } else if (grid[j][cur] == -1) {
                    if (cur == 0) {
                        ans[i] = -1;
                        break;
                    } else if (cur > 0 && grid[j][cur - 1] == 1) {
                        ans[i] = -1;
                        break;
                    } else {
                        cur--;
                    }
                }
            }
            if (ans[i] != -1) ans[i] = cur;
        }
        return ans;
    }
};