class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a1, a2;
        {
            unordered_map<int, bool> ump, tmp;
            for (auto e : nums2) ump[e] = true;
            for (auto e : nums1) {
                if (ump.find(e) == ump.end() && tmp.find(e) == tmp.end()) {
                    tmp[e] = true;
                    a1.push_back(e);
                }
            }
        }
        {
            unordered_map<int, bool> ump, tmp;
            for (auto e : nums1) ump[e] = true;
            for (auto e : nums2) {
                if (ump.find(e) == ump.end() && tmp.find(e) == tmp.end()) {
                    tmp[e] = true;
                    a2.push_back(e);
                }
            }
        }
        return {a1, a2};
    }
};