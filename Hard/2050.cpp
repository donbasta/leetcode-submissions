class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int dp[n], in[n];
        memset(in, 0, sizeof(in));
        memset(dp, 0, sizeof(dp));
        vector<int> nx[n];
        for (auto r : relations) {
            in[r[1] - 1]++;
            nx[r[0] - 1].push_back(r[1] - 1);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q.emplace(i), dp[i] = time[i];
        }
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            for (auto c : nx[now]) {
                dp[c] = max(dp[c], time[c] + dp[now]);
                in[c]--;
                if (in[c] == 0) {
                    q.emplace(c);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};