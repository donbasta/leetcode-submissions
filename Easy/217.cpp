class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se;
        for (auto e : nums) {
            se.insert(e);
        }
        return se.size() < nums.size();
    }
};