class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> ret;
        using ll = long long;
        int n = candiesCount.size();
        vector<ll> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = (i > 0 ? pre[i - 1] : 0) + candiesCount[i];
        }
        for (auto q : queries) {
            ll mx = 1ll * q[2] * (q[1]);
            ll mn = 1ll * q[1];
            ll fi = (q[0] == 0 ? 1 : pre[q[0] - 1] + 1);
            ll la = pre[q[0]];
            // cout << mx << ' ' << mn << ' ' << fi << ' ' << la << '\n';
            ret.push_back(fi <= mx + q[2] && la >= mn + 1);
        }
        return ret;
    }
};