class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int t = (n - 2) / 3;
        int ans = 1;
        for (int i = 0; i < t; i++) ans *= 3;
        ans *= (((n + 1) % 3) + 2);
        return ans;
    }
};