class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<int, unordered_map<int, int>> ump;
        for (auto c : coordinates) {
            int i = c[0], j = c[1];
            if (i > 0 && j > 0) ump[i - 1][j - 1]++;
            if (i < m - 1 && j > 0) ump[i][j - 1]++;
            if (i > 0 && j < n - 1) ump[i - 1][j]++;
            if (i < m - 1 && j < n - 1) ump[i][j]++;
        }
        vector<long long> cnt(5);
        cnt[0] = 1ll * (m - 1) * (n - 1);
        for (auto e : ump) {
            cnt[0] -= 1ll * e.second.size();
            for (auto f : e.second) {
                cnt[f.second]++;
            }
        }
        return cnt;
    }
};