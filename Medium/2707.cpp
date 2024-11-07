class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        const int INF = 2e9;
        vector<int> dp(n + 1, INF);
        set<string> word_set;
        for (auto e : dictionary) word_set.insert(e);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i + 1] = min(dp[i + 1], dp[j] + i + 1 - j);
            }
            for (int j = i; j >= 0; j--) {
                if (word_set.count(s.substr(j, i - j + 1))) {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }
        return dp[n];
    }
};