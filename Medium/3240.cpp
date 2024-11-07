class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                vector<int> tmp(2);
                tmp[grid[i][j]]++;
                tmp[grid[m - 1 - i][j]]++;
                tmp[grid[i][n - 1 - j]]++;
                tmp[grid[m - 1 - i][n - 1 - j]]++;
                ans += min(tmp[0], tmp[1]);
            }
        }
        vector<int> cnt(3);
        if (m & 1) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[m / 2][i] != grid[m / 2][n - 1 - i]) cnt[2]++;
                else cnt[grid[m / 2][i]]++;
            }
        }
        if (n & 1) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] != grid[m - 1 - i][n / 2]) cnt[2]++;
                else cnt[grid[i][n / 2]]++;
            }
        }

        if (cnt[1] % 2 == 0) {
            ans += cnt[2];
        } else {
            if (cnt[2] >= 1) ans += cnt[2];
            else ans += 2;
        }

        if ((m & 1) && (n & 1) && (grid[m / 2][n / 2] == 1)) ans++;
        return ans;
    }
};