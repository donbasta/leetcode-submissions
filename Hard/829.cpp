class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // a + ... + (a + d - 1)
        // 2n = (2a + d - 1) * d
        int ans = 0;
        n *= 2;
        for (int i = 1; i * i <= n; i++) {
            if (n % i != 0) continue;
            int j = n / i;
            ans += ((i + j) & 1);
        }
        return ans;
    }
};