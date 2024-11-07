class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) ret -= i;
            else ret += i;
        }
        return ret;
    }
};