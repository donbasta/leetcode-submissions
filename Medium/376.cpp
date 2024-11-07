class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};