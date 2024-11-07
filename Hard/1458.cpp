class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ndp[m][n];
        for (int i = 0; i < n; i++) {
            int tmp = nums1[0] * nums2[i];
            ndp[0][i] = tmp;
            if (i > 0) ndp[0][i] = max(ndp[0][i], ndp[0][i - 1]);
        }
        for (int i = 0; i < m; i++) {
            int tmp = nums1[i] * nums2[0];
            ndp[i][0] = tmp;
            if (i > 0) ndp[i][0] = max(ndp[i][0], ndp[i - 1][0]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int tmp = nums1[i] * nums2[j];
                tmp = max(tmp, ndp[i - 1][j - 1] + nums1[i] * nums2[j]);
                ndp[i][j] = max(ndp[i - 1][j], ndp[i][j - 1]);
                ndp[i][j] = max(ndp[i][j], tmp);
            }
        }
        return ndp[m - 1][n - 1];
    }
};