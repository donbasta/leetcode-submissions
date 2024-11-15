class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int cur = 1;
        if (n == 0) return 1;
        while (n) {
            if (n % 2 == 0) {
                ans += cur;
            }
            n >>= 1, cur <<= 1;
        }
        return ans;
    }
};