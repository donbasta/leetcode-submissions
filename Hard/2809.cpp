class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b) -> bool {
            return nums2[a] < nums2[b];
        });
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = nums1[idx[0]] + nums2[idx[0]];
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j >= 1; j--) {
                dp[j] = max(dp[j], dp[j - 1] + nums1[idx[i]] + nums2[idx[i]] * j);
            }
        }
        int P = accumulate(nums1.begin(), nums1.end(), 0);
        int Q = accumulate(nums2.begin(), nums2.end(), 0);
        if (P <= x) return 0;
        for (int i = 1; i <= n; i++) {
            int tot = P + Q * i - dp[i];
            if (tot <= x) {
                return i;
            }
        }
        return -1;
    }
};
