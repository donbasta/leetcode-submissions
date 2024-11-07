class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> mx(26, -1);
        int n = s.length();
        vector<int> dp(n);
        dp[0] = 1;
        mx[s[0] - 'a'] = 1;
        for (int i = 1; i < n; i++) {
            int tmp = 1;
            for (int j = 0; j < 26; j++) {
                if (abs(j - (s[i] - 'a')) > k) continue;
                if (mx[j] == -1) continue;
                tmp = max(tmp, 1 + mx[j]);
            }
            dp[i] = tmp;
            mx[s[i] - 'a'] = max(mx[s[i] - 'a'], dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};