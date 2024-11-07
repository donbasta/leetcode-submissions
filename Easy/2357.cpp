class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> se;
        for (auto e : nums) if (e != 0) se.insert(e);
        return se.size();
    }
};