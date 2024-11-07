class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> pre(n), dp(n), ndp(n);
        pre[0] = 1;
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + 1;
        for (int i = 0; i < n; i++) {
            int kiri = prizePositions[i] - k;
            int a = lower_bound(prizePositions.begin(), prizePositions.end(), kiri) - prizePositions.begin();
            dp[i] = pre[i] - (a ? pre[a - 1] : 0);
            if (i == 0) ndp[i] = dp[i];
            else ndp[i] = max(ndp[i - 1], dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int kiri = prizePositions[i] - k;
            int a = lower_bound(prizePositions.begin(), prizePositions.end(), kiri) - prizePositions.begin();
            ans = max(ans, dp[i] + (a ? ndp[a - 1] : 0));
        }
        return ans;
    }
};