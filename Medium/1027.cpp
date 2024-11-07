class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<int> pos(505, -1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1005, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1000; j++) {
                int sel = j - 500;
                if (nums[i] - sel < 0 || nums[i] - sel > 500) continue;
                if (pos[nums[i] - sel] != -1) {
                    dp[i][j] = dp[pos[nums[i] - sel]][j] + 1;
                }
            }
            pos[nums[i]] = i;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1000; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};