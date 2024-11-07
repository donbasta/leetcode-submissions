class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<pair<int, int>> ve;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            ve.emplace_back(arr[i], i);
        }
        sort(ve.begin(), ve.end());
        vector<bool> udh(n);
        vector<int> dp(n, 1);
        int last = -1;
        for (int i = 0; i < n; i++) {
            int curMid = ve[i].second;
            int tmp = 1;
            for (int j = curMid - 1; j >= max(0, curMid - d); j--) {
                if (!udh[j]) break;
                tmp = max(tmp, 1 + dp[j]);
            }
            for (int j = curMid + 1; j <= min(n - 1, curMid + d); j++) {
                if (!udh[j]) break;
                tmp = max(tmp, 1 + dp[j]);
            }
            dp[curMid] = tmp;
            if (i + 1 < n && ve[i + 1].first > ve[i].first) {
                for (int j = last + 1; j <= i; j++) {
                    udh[ve[j].second] = true;
                }
                last = i;
            }
        }
        int ans = 1;
        for (auto e : dp) ans = max(ans, e);
        return ans;
    }
};