class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(k + 1), f(k + 1), pr(k + 1);
        for (int i = 0; i < n / 2; i++) {
            cnt[abs(nums[i] - nums[n - 1 - i])]++;

            int a = nums[i], b = nums[n - 1 - i];
            f[max({a, b, k - a, k - b})]++;
        }
        pr[0] = f[0];
        for (int i = 1; i <= k; i++) {
            pr[i] = pr[i - 1] + f[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= k; i++) {
            if (k - i >= i) {
                ans = min(ans, n / 2 - cnt[i]);
            } else {
                ans = min(ans, n / 2 - cnt[i] + pr[i - 1]);
            }
        }
        return ans;
    }
};