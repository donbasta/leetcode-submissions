class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> adj[n];
        int to[n];
        memset(to, 0, sizeof(to));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ni = words[i].length();
                int nj = words[j].length();
                if (ni - nj != 1) continue;
                int len = 0;
                for (int k = 0; k < nj; k++) {
                    if (words[i][k] != words[j][k]) break;
                    len++;
                }
                for (int k = nj - 1; k >= 0; k--) {
                    if (words[i][k + 1] != words[j][k]) break;
                    len++;
                }
                if (len >= nj) {
                    adj[j].push_back(i);
                    to[i]++;
                }
            }
        }
        queue<int> Q;
        int dp[n];
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int i = 0; i < n; i++) {
            if (to[i] == 0) {
                Q.emplace(i);
            }
        }
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : adj[now]) {
                dp[c] = max(dp[c], dp[now] + 1);
                --to[c];
                if (to[c] == 0) Q.emplace(c);
            }
        }
        int ans = *max_element(dp, dp + n);
        return ans;
    }
};