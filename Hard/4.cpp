class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> lmao;
        for (auto e : nums1) lmao.push_back(e);
        for (auto e : nums2) lmao.push_back(e);
        sort(lmao.begin(), lmao.end());
        int sz = lmao.size();
        if (sz & 1) {
            return lmao[sz / 2];
        }
        return double(lmao[(sz - 1) / 2] + lmao[sz / 2]) / 2.0;
    }
};