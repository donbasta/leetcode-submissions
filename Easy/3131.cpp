class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int sum = 0, n = nums1.size();
        for (int i = 0; i < n; i++) {
            sum += nums2[i] - nums1[i];
        }
        return sum / n;
    }
};