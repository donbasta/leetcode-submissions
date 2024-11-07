class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> se;
        for (auto e : nums) se.insert(e);
        int ans = -1;
        for (auto e : se) {
            if (se.count(-e)) {
                ans = max(ans, e);
            }
        }
        return ans;
    }
};