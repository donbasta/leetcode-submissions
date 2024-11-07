class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int a1 = accumulate(nums1.begin(), nums1.end(), 0);
        int a2 = accumulate(nums2.begin(), nums2.end(), 0);
        int n = nums1.size();
        int mn1 = 0, mn2 = 0;
        int ans = max(a1, a2);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            c1 += nums1[i], c2 += nums2[i];
            ans = max(ans, a1 + c2 - c1 - mn1);
            ans = max(ans, a2 + c1 - c2 - mn2);
            mn1 = min(mn1, c2 - c1);
            mn2 = min(mn2, c1 - c2);
        }
        return ans;
    }
};