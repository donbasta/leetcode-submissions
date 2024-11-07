class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        bool DP[n][200 * 30 + 5];
        memset(DP, false, sizeof(DP));
        auto dp = [&](int x, int y) -> bool& {
            bool &ret = DP[x][y + 100 * 30];
            return ret;
        };

        dp(0, stones[0]) = true;
        dp(0, -stones[0]) = true;
        
        for (int i = 1; i < n; i++) {
            for (int j = -i * 100; j <= i * 100; j++) {
                if (dp(i - 1, j)) {
                    dp(i, j + stones[i]) = true;
                    dp(i, j - stones[i]) = true;
                }
            }
        }
        for (int i = 0; i <= 100; i++) {
            if (dp(n - 1, i)) return i;
        }
        return -1;
    }
};