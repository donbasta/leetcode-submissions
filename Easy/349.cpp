class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> se, ss;
        vector<int> ret;
        for (auto e : nums1) se.insert(e);
        for (auto e : nums2) if (se.count(e)) ss.insert(e);
        return vector<int>(ss.begin(), ss.end());
    }
};