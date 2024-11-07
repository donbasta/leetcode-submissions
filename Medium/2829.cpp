class Solution {
public:
    int minimumSum(int n, int k) {
        if (n <= (k / 2)) {
            return n * (n + 1) / 2;
        }
        n -= (k / 2);
        int ans = (k / 2) * (k / 2 + 1) / 2;
        ans += n * (2 * k + n - 1) / 2;
        return ans;
    }
};