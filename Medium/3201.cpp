class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for (auto& e : nums) {
            e %= 2;
        }
        vector<int> prv(n, -1);
        int last_val = nums[0], last_idx = 0;
        prv[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == last_val) {
                prv[i] = prv[i - 1];
            } else {
                prv[i] = i;
                last_val = nums[i];
                last_idx = i;
            }
        }
        
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            if (prv[i] == 0) continue;
            dp[i] = max(dp[i], dp[prv[i] - 1] + 1);
        }
        int ans = *max_element(dp.begin(), dp.end());
        ans = max(ans, (int)count(nums.begin(), nums.end(), 0));
        ans = max(ans, (int)count(nums.begin(), nums.end(), 1));
        return ans;
    }
};