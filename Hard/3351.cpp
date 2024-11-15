class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int ans = 0;
        const int MOD = 1e9 + 7;
        map<int, int> mp, sum;
        ans = nums[0];
        mp[nums[0]] = 1;
        sum[nums[0]] = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            ans = (ans + nums[i]) % MOD;
            mp[nums[i]]++;
            sum[nums[i]] = (sum[nums[i]] + nums[i]) % MOD;
            if (mp.count(nums[i] - 1)) {
                ans = (ans + sum[nums[i] - 1]) % MOD;
                int add = 1ll * nums[i] * mp[nums[i] - 1] % MOD;
                ans = (1ll * ans + add) % MOD;
                sum[nums[i]] = (sum[nums[i]] + add) % MOD;
                sum[nums[i]] = (sum[nums[i]] + sum[nums[i] - 1]) % MOD;
                mp[nums[i]] = (mp[nums[i]] + mp[nums[i] - 1]) % MOD;
            }
            if (mp.count(nums[i] + 1)) {
                ans = (ans + sum[nums[i] + 1]) % MOD;
                int add = 1ll * nums[i] * mp[nums[i] + 1] % MOD;
                ans = (1ll * ans + add) % MOD;
                sum[nums[i]] = (sum[nums[i]] + add) % MOD;
                sum[nums[i]] = (sum[nums[i]] + sum[nums[i] + 1]) % MOD;
                mp[nums[i]] = (mp[nums[i]] + mp[nums[i] + 1]) % MOD;
            }
        }
        return ans;
    }
};