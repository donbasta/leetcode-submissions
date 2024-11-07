class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ret = 0;
        for (int i = 0; i < 31; i++) {
            int tmp = 0;
            for (auto e : nums) {
                tmp += ((e >> i) & 1);
            }
            if (tmp >= k) {
                ret ^= (1 << i);
            }
        }
        return ret;
    }
};