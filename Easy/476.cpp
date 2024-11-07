class Solution {
public:
    int findComplement(int num) {
        int pw = 1;
        int ans = 0;
        while (num) {
            if (!(num & 1)) {
                ans += pw;
            }
            pw <<= 1;
            num >>= 1;
        }
        return ans;
    }
};