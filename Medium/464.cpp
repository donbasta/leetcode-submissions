class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        vector<int> dp(1 << maxChoosableInteger);
        for (int i = 0; i < (1 << maxChoosableInteger); i++) {
            int tmp = 0;
            for (int j = 0; j < maxChoosableInteger; j++) {
                int on = i & (1 << j);
                if (!on) tmp += (j + 1);
                else if (dp[i ^ (1 << j)] == 2) {
                    dp[i] = 1;
                }
            }
            if ((tmp >= desiredTotal) || (dp[i] == 0)) dp[i] = 2;
        }
        if (dp[(1 << maxChoosableInteger) - 1] == 1) return true;
        return false;
    }
};