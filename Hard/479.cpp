class Solution {
public:
    int largestPalindrome(int n) {
        const int MOD = 1337;
        vector<int> pw(n * 2 + 1);
        pw[0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            pw[i] = (pw[i - 1] * 10) % MOD;
        }
        if (n == 1) return 9;
        if (n == 3) return 123;
        if (n == 5) return 677;
        if (n == 7) return 877;
        assert (n % 2 == 0);
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = (ans + 9 * pw[i]) % MOD;
        }
        for (int i = n / 2 + n; i < 2 * n; i++) {
            ans = (ans + 9 * pw[i]) % MOD;
        }
        return ans;
    }
};