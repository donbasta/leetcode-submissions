class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for (auto e : nums1) s1.insert(e);
        for (auto e : nums2) s2.insert(e);
        int c1 = 0, c2 = 0;
        for (auto e : nums1) c1 += s2.count(e);
        for (auto e : nums2) c2 += s1.count(e);
        return vector<int>{c1, c2};
    }
};