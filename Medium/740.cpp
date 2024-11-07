class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        vector<int> lmao;
        for (auto e : cnt) lmao.push_back(e.first);
        sort(lmao.begin(), lmao.end());
        int n = lmao.size();
        vector<int> dp(n), best(n);
        dp[0] = cnt[lmao[0]] * lmao[0];
        if (n == 1) {
            return dp[0];
        }
        dp[1] = cnt[lmao[1]] * lmao[1];
        if (lmao[0] < lmao[1] - 1) dp[1] += dp[0];
        best[0] = dp[0];
        best[1] = max(dp[0], dp[1]);
        for (int i = 2; i < n; i++) {
            if (lmao[i - 1] == lmao[i] - 1) {
                dp[i] = cnt[lmao[i]] * lmao[i] + best[i - 2];
            } else {
                dp[i] = cnt[lmao[i]] * lmao[i] + best[i - 1];
            }
            best[i] = max(best[i - 1], dp[i]);
        }
        return best[n - 1];
    }
};