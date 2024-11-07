class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1 << maximumBit) - 1;
        int tot = 0;
        for (auto& e : nums) {
            e &= mask;
            tot ^= e;
        }
        vector<int> ret;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            ret.push_back(tot ^ mask);
            tot ^= nums[i];
        }
        return ret;
    }
};