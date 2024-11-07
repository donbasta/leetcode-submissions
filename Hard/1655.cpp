class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> cnt;
        for (auto c : nums) {
            cnt[c]++;
        }
        vector<int> freq;
        for (auto c : cnt) {
            freq.emplace_back(c.second);
        } 
        int sz = freq.size();
        int m = quantity.size();
        // vector<vector<bool>> dp(sz, vector<bool>(1 << m));
        bool dp[sz][1 << m];
        memset(dp, 0, sizeof(dp));
        int sum[1 << m];
        // vector<int> sum(1 << m);
        for (int i = 0; i < (1 << m); i++) {
            sum[i] = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) sum[i] += quantity[j];
            }
        }
        for (int i = 0; i < (1 << m); i++) {
            dp[0][i] = (sum[i] <= freq[0]);
        }
        auto is_subset = [&](int a, int b) -> bool {
            return (a == (a & b));
        };
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < (1 << m); j++) {
                for (int k = 0; k < (1 << m); k++) {
                    if (!is_subset(k, j)) continue;
                    dp[i][j] = dp[i][j] || (dp[i - 1][j ^ k] && (sum[k] <= freq[i]));
                }
            }
        }
        return dp[sz - 1][(1 << m) - 1];
    }
};