class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ks = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int b = 0;
        for (int i = 0; i < 32; i++) {
            if ((ks >> i) & 1) {
                b = (1 << i);
                break;
            }
        }
        assert(b);
        int x = 0, y = 0;
        for (auto e : nums) {
            if (e & b) x ^= e;
            else y ^= e;
        }
        return vector<int>{x, y};
    }
};