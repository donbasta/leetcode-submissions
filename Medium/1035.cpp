class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m1 = nums1.size();
        int m2 = nums2.size();
        int dp[m1 + 1][m2 + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m1; i++) {
            for (int j = 1; j <= m2; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m1][m2];
    }
};