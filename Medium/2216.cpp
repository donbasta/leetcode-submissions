class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int dp[n], le[n];
        dp[0] = 1;
        le[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) le[i] = le[i - 1];
            else le[i] = i;
        }
        for (int i = 1; i < n; i++) {
            int tmp = INT_MAX;
            tmp = min(tmp, 1 + dp[i - 1]);
            int l = le[i];
            if (l > 0) tmp = min(tmp, (l >= 2 ? dp[l - 2] : 0) + i - l);
            dp[i] = tmp;
        }
        return dp[n - 1];
    }
};