class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            int tmp = 0;
            for (auto e : nums) tmp += ((e >> i) & 1);
            if (tmp & 1) ans ^= (1 << i);
        }
        return ans;
    }
};