class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        vector<long long> dp(n);
        int kananMin = -1, kananMax = -1;
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                kananMin = -1, kananMax = -1, start = -1;
            } else {
                if (start == -1) {
                    start = i;
                }
                if (minK == maxK) {
                    dp[i] = (i ? dp[i - 1] : 0) + 1;
                    continue;
                }
                if (nums[i] == maxK) {
                    if (kananMin != -1) dp[i] = 1ll * (kananMin - start + 1);
                    kananMax = i;
                } else if (nums[i] == minK) {
                    if (kananMax != -1) dp[i] = 1ll * (kananMax - start + 1);
                    kananMin = i;
                } else {
                    dp[i] = (i ? dp[i - 1] : 0);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};