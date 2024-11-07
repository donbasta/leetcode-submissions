class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i1 = 0, i2 = 0;
        int ans = 0;
        while (i1 < n) {
            while (i2 < m && i2 < i1) i2++;
            while (i2 < m && nums2[i2] >= nums1[i1]) i2++;
            if (i2 > 0 && i2 - 1 >= i1 && nums2[i2 - 1] >= nums1[i1]) {
                ans = max(ans, i2 - 1 - i1);
            }
            i1++;
        }
        return ans;
    }
};