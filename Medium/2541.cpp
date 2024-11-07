class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            if (nums1 == nums2) return 0;
            else return -1;
        }
        using ll = long long;
        int n = nums1.size();
        ll a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (abs(nums1[i] - nums2[i]) % k != 0) return -1;
            a += (nums1[i] - nums2[i]) / k;
            if (nums1[i] >= nums2[i]) b += (nums1[i] - nums2[i]) / k;
        }
        if (a != 0) return -1;
        return b;
    }
};