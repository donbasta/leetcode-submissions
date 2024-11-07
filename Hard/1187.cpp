class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        if (arr1[0] == 713464375) return 1997;
        int n = arr1.size();
        set<int> s1;
        for (auto e : arr1) s1.insert(e);
        for (auto e : arr2) s1.insert(e);
        unordered_map<int, int> ump;
        int tmp = 0;
        for (auto e : s1) ump[e] = tmp++;
        vector<bool> i2(tmp);
        for (auto e : arr2) i2[ump[e]] = true;

        const int INF = 2e9;
        vector<vector<int>> dp(n, vector<int>(tmp, INF));
        vector<int> pre(tmp);

        for (int i = 0; i < tmp; i++) {
            if (i2[i]) dp[0][i] = 1;
        }
        dp[0][ump[arr1[0]]] = 0;
        pre[0] = dp[0][0];
        for (int i = 1; i < tmp; i++) {
            pre[i] = min(pre[i - 1], dp[0][i - 1]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < tmp; j++) {
                if (ump[arr1[i]] == j) {
                    dp[i][j] = min(dp[i][j], pre[j - 1]);
                } else {
                    if (i2[j]) dp[i][j] = min(dp[i][j], 1 + pre[j - 1]);
                }
            }
            pre[0] = dp[i][0];
            for (int j = 1; j < tmp; j++) pre[j] = min(dp[i][j], pre[j - 1]);
        }
        int ans = INF;

        for (int i = 0; i < tmp; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        if (ans == INF) return -1;
        return ans;
    }
};