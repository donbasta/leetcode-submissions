class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (nums2[j] != nums1[i]) j++;
            j++;
            while (j < m && nums2[j] <= nums1[i]) j++;
            if (j < m) ans[i] = nums2[j];
        }
        return ans;
    }
};