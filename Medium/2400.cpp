class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<int> curs;
        unordered_map<int, int> dp;
        curs.push_back(startPos);
        const int MOD = 1e9 + 7;
        dp[startPos] = 1;
        for (int i = 1; i <= k; i++) {
            unordered_map<int, int> ndp;
            unordered_map<int, bool> ada;
            for (auto e : curs) {
                ndp[e - 1] = (ndp[e - 1] + dp[e]) % MOD;
                ndp[e + 1] = (ndp[e + 1] + dp[e]) % MOD;
                if (abs((e - 1) - endPos) <= (k - i)) ada[e - 1] = true;
                if (abs((e + 1) - endPos) <= (k - i)) ada[e + 1] = true;
            }
            curs.clear();
            for (auto e : ada) curs.push_back(e.first);
            dp = ndp;
        }
        return dp[endPos];
    }
};