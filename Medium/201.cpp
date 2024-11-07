class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            if (!(left & (1 << i))) continue;
            if (i < 30) {
                int nx = 1 << (i + 1);
                int msk = left & (nx - 1);
                if (msk + (right - left) < nx) {
                    ans += (1 << i);
                }
            } else {
                ans += (1 << i);
            }
        }
        return ans;
    }
};