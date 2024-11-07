class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        using ll = long long;
        
        vector<vector<ll>> ret(m, vector<ll>(n));
        ll tot = accumulate(rowSum.begin(), rowSum.end(), 0ll);
        for (int i = 0; i < n - 1; i++) ret[m - 1][i] = colSum[i];
        for (int i = 0; i < m - 1; i++) ret[i][n - 1] = rowSum[i];
        ll rb = 1ll * rowSum[m - 1] - tot + colSum[n - 1];
        ret[m - 1][n - 1] = rb;

        set<pair<ll, int>> sr, sc;
        for (int i = 0; i < m - 1; i++) sr.emplace(ret[i][n - 1], i);
        for (int i = 0; i < n - 1; i++) sc.emplace(ret[m - 1][i], i);
        while (ret[m - 1][n - 1] < 0) {
            auto rr = *sr.rbegin(), cc = *sc.rbegin();
            assert (rr.first > 0);
            assert (cc.first > 0);
            sr.erase(rr);
            sc.erase(cc);
            ll delta = min(rr.first, cc.first);
            ret[m - 1][n - 1] += delta;
            ret[rr.second][cc.second] += delta;
            ret[rr.second][n - 1] -= delta;
            ret[m - 1][cc.second] -= delta;
            if (rr.first - delta > 0) {
                sr.emplace(rr.first - delta, rr.second);
            }
            if (cc.first - delta > 0) {
                sc.emplace(cc.first - delta, cc.second);
            }
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) ans[i][j] = ret[i][j];
        return ans;
    }
};