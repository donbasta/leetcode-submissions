class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long mid = target / 2;
        if (n < mid) {
            return 1ll * n * (n + 1) / 2;
        }
        long long ret = 0;
        ret += mid * (mid + 1) / 2;
        long long sisa = n - mid;
        ret += (sisa) * (sisa - 1 + 2 * target) / 2;
        return ret;
    }
};