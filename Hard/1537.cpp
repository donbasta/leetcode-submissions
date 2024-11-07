class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        long long dp1[n1], dp2[n2];
        while (i1 < n1 || i2 < n2) {
            if (i1 == n1) {
                dp2[i2] = 1ll * nums2[i2] + (i2 > 0 ? dp2[i2 - 1] : 0);
                i2++;
            } else if (i2 == n2) {
                dp1[i1] = 1ll * nums1[i1] + (i1 > 0 ? dp1[i1 - 1] : 0);
                i1++;
            } else {
                if (nums1[i1] < nums2[i2]) {
                    dp1[i1] = 1ll * nums1[i1] + (i1 > 0 ? dp1[i1 - 1] : 0);
                    i1++;
                } else if (nums1[i1] > nums2[i2]) {
                    dp2[i2] = 1ll * nums2[i2] + (i2 > 0 ? dp2[i2 - 1] : 0);
                    i2++;
                } else {
                    long long p1 = (i1 > 0 ? dp1[i1 - 1] : 0);
                    long long p2 = (i2 > 0 ? dp2[i2 - 1] : 0);
                    dp1[i1] = 1ll * nums1[i1] + max(p1, p2);
                    dp2[i2] = 1ll * nums2[i2] + max(p1, p2);
                    i1++, i2++;
                }
            }
        }
        long long ans = max(dp1[n1 - 1], dp2[n2 - 1]);
        long long MOD = 1e9 + 7;
        return (ans % MOD);
    }
};