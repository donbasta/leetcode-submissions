class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = nums[0];
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int tmp = (1ll * nums[i] * nums[i]) % mod;
            tmp = (1ll * tmp * sum) % mod;
            ans = (ans + tmp) % mod;
            if (i < n - 1) {
                sum = (2ll * sum - nums[i] + nums[i + 1]) % mod;
            }
        }
        if (ans < 0) ans += mod;
        return ans;
    }
};