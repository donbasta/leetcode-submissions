class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> cnt(sz, vector<int>(2));
        for (int i = 0; i < sz; i++) {
            for (auto c : strs[i]) {
                cnt[i][c - '0']++;
            }
        }
        vector<vector<vector<int>>> DP(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        const function<int(int, int, int)> dp = [&](int idx, int mm, int nn) -> int {
            if (idx == sz) return 0;
            if (DP[idx][mm][nn] != -1) return DP[idx][mm][nn];
            int ret = dp(idx + 1, mm, nn);
            if (cnt[idx][0] <= mm && cnt[idx][1] <= nn) {
                ret = max(ret, 1 + dp(idx + 1, mm - cnt[idx][0], nn - cnt[idx][1]));
            }
            return DP[idx][mm][nn] = ret;
        };
        return dp(0, m, n);
    }
};