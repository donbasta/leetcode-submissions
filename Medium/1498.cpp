class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = n - 1;
        int ans = 0;
        int pw2[n + 1];
        pw2[0] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++) pw2[i] = (1ll * 2 * pw2[i - 1]) % MOD;
        for (int i = 0; i < n; i++) {
            while (r > i && nums[i] + nums[r] > target) r--;
            if (r == i && (nums[i] * 2 > target)) break;
            ans = (ans + pw2[r - i]) % MOD;
            if (r == i) break;
        }
        return ans;
    }
};