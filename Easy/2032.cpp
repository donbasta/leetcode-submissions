class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int, set<int>> mp;
        for (auto e : nums1) mp[e].insert(1);
        for (auto e : nums2) mp[e].insert(2);
        for (auto e : nums3) mp[e].insert(3);
        vector<int> ans;
        for (auto e : mp) {
            if (e.second.size() >= 2) ans.push_back(e.first);
        }
        return ans;
    }
};