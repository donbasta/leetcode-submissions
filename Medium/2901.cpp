class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n), prev(n, -1);
        dp[0] = 1;
        auto ok = [&](int a, int b) -> bool {
            int sa = words[a].length();
            int sb = words[b].length();
            if (sa != sb) return false;
            int beda = 0;
            for (int i = 0; i < sa; i++) {
                beda += words[a][i] != words[b][i];
            }
            return beda == 1;
        };
        for (int i = 1; i < n; i++) {
            int mx = 1, idx = -1;
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && ok(i, j)) {
                    int tmp = 1 + dp[j];
                    if (tmp > mx) {
                        mx = tmp;
                        idx = j;
                    }
                }
            }
            dp[i] = mx;
            prev[i] = idx;
        }
        int mx = 0;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }
        vector<string> ret;
        int cur = idx;
        while (cur != -1) {
            ret.push_back(words[cur]);
            cur = prev[cur];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};