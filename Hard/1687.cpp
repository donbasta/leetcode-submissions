class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        // dp[i] = dp[i - j] + (2 + (c[i - j + 1] != c[i - j + 2]) + ... + (c[i - 1] != c[i]))
        // dp[i] = dp[i - j] + (2 + p[i] - p[i - j + 1]);

        int n = boxes.size();
        using ll = long long;
        const ll INF = 1e18;
        vector<ll> dp(n, INF), pre(n), pw(n);
        pw[0] = boxes[0][1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (boxes[i][0] != boxes[i - 1][0]);
            pw[i] = pw[i - 1] + boxes[i][1];
        }
        dp[0] = 2;
        set<pair<ll, int>> se;
        se.emplace(0, -1);
        se.emplace(dp[0] - pre[1], 0);
        int cur_le = -1;
        for (int i = 1; i < n; i++) {
            int le = max(0, i - maxBoxes + 1);
            int idx = lower_bound(pw.begin(), pw.end(), pw[i] - maxWeight) - pw.begin();
            if (pw[i] <= maxWeight) idx = -1;
            le = max(le, idx + 1);
            while (cur_le < le - 1) {
                se.erase(make_pair((cur_le >= 0 ? dp[cur_le] : 0) - pre[cur_le + 1], cur_le));
                cur_le++;
            }
            dp[i] = 2 + pre[i] + se.begin()->first;
            if (i < n - 1) se.emplace(dp[i] - pre[i + 1], i);
        }
        return dp.back();
    }
};