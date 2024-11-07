class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size(), b = nums2.size();
        vector<vector<int>> dp(a + 1, vector<int>(b + 1));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                }
            }
        }
        int ret = 0;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};