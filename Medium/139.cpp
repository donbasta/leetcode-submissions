class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> wordSet;
        for (auto word : wordDict) {
            wordSet.insert(word);
        }
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j + 1)) != wordSet.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};