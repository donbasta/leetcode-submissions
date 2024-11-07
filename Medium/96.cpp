class Solution {
public:
    int numTrees(int n) {
        vector<int> DP(n + 1, -1);
        const function<int(int)> dp = [&](int x) -> int {
            if (x <= 1) return 1;
            if (DP[x] != -1) return DP[x];
            int& tmp = DP[x];
            tmp = 0;
            for (int i = 0; i <= (x - 1) / 2; i++) {
                int u = dp(i), v = dp(x - 1 - i);
                tmp += u * v;
                if (i * 2 != (x - 1)) tmp += u * v;
            }
            return tmp;
        };

        return dp(n);
    }
};