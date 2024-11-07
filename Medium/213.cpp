class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];

        vector<int> dp(n + 1);

        dp[1] = nums[0];
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            dp[i + 1] = nums[i] + tmp;
            tmp = max(tmp, dp[i]);
        }
        int ans1 = 0;
        for (int i = 1; i < n; i++) {
            ans1 = max(ans1, dp[i]);
        }

        dp[1] = nums[1];
        tmp = 0;
        for (int i = 2; i < n; i++) {
            dp[i + 1] = nums[i] + tmp;
            tmp = max(tmp, dp[i]);
        }
        int ans2 = 0;
        for (int i = 2; i <= n; i++) {
            ans2 = max(ans2, dp[i]);
        }
        
        return max(ans1, ans2);
    }
};