class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        if (n == 0) return ans;
        for (int i = 1; i <= n; i++) {
            int tmp = 9;
            for (int j = 1; j < i; j++) {
                tmp *= (10 - j);
            }
            ans += tmp;
        }
        return ans;
    }
};