class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> se;
        for (auto e : nums1) se.insert(e);
        for (auto e : nums2) if (se.count(e)) return e;
        return -1;
    }
};