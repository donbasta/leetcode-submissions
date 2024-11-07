class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int M = 16;
        int dp[1 << M];
        memset(dp, 0, sizeof(dp));
        for (auto c : nums) dp[c]++;
        for (int i = 0; i < M; i++) {
            for (int j = (1 << M) - 1; j >= 0; j--) {
                if ((j >> i) & 1) dp[j] += dp[j ^ (1 << i)];
            }
        }
        int n = nums.size();
        int mx_mask = (1 << M) - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += dp[mx_mask ^ (nums[i] & nums[j])];
            }
        }
        return ans;
    }
};