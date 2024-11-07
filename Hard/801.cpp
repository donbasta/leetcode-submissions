class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        const int INF = 2e9;
        vector<int> d0(n, INF), d1(n, INF);
        d0[0] = 0, d1[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                d0[i] = min(d0[i], d0[i - 1]);
                d1[i] = min(d1[i], 1 + d1[i - 1]);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                d0[i] = min(d0[i], d1[i - 1]);
                d1[i] = min(d1[i], 1 + d0[i - 1]);
            }
        }
        return min(d0[n - 1], d1[n - 1]);
    }
};