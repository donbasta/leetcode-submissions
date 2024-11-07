class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        const int B = 30;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int tmp = 0;
            for (auto e : nums) {
                if ((e >> i) & 1) tmp++;
            }
            if (tmp > 0) ans += 1 << i;
        }
        return ans;
    }
};