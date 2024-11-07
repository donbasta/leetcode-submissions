class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s = k;
        for (auto e : nums) s ^= e;
        return __builtin_popcount(s);
    }
};