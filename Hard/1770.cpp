class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        for (int op = 1; op <= m; op++) {
            for (int j = 0; j <= op; j++) {
                int tmp = INT_MIN;
                if (j >= 1) tmp = max(tmp, dp[j - 1][op - j] + multipliers[op - 1] * nums[j - 1]);
                if (op - j >= 1) tmp = max(tmp, dp[j][op - j - 1] + multipliers[op - 1] * nums[n - (op - j)]);
                dp[j][op - j] = tmp;
            }   
        }
        int ans = INT_MIN;
        for (int i = 0; i <= m; i++) {
            ans = max(ans, dp[i][m - i]);
        }
        return ans;
    }
};