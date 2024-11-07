class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1) return n;
        int t = 31 - __builtin_clz(n);
        if ((n >> (t - 1)) & 1) {
            return (1 << (t + 1)) - 1 - minimumOneBitOperations(n - (1 << t));
        }
        return (1 << t) + minimumOneBitOperations(n - (1 << (t - 1)));
    }
};