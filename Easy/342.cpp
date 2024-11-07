class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && !(n & (n - 1)) && (__builtin_clz(n) & 1);
    }
};