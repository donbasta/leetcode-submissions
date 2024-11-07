class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> se;
        for (auto n : nums) se.insert(n);
        while (se.count(original)) {
            original *= 2;
        }
        return original;
    }
};