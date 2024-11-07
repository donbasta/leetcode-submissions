class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        int ret = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                pos.push_back(i);
            }
        }
        if (pos.empty()) return 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < pos.size() - 1; i++) {
            ret = 1ll * ret * (pos[i + 1] - pos[i]) % MOD;
        }
        return ret;
    }
};