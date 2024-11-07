class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int dp[1 << n];
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i < (1 << n); i++) {
            int sz = __builtin_popcount(i);
            if (sz & 1) continue;
            int pos[sz];
            int idx = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) pos[idx++] = j;
            }
            for (int x = 0; x < sz; x++) {
                for (int y = x + 1; y < sz; y++) {
                    dp[i] = max(dp[i], dp[i ^ (1 << pos[x]) ^ (1 << pos[y])] + (sz / 2) * __gcd(nums[pos[x]], nums[pos[y]]));
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};