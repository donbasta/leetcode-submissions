using ll = long long;

class Solution {
public:
    ll minimumMoney(vector<vector<int>>& trx) {
        int n = trx.size();
        ll rem = -1, tot = 0;
        vector<ll> idx;
        for (int i = 0; i < n; i++) {
            ll net = trx[i][0] - trx[i][1];
            if (net > 0) {
                idx.push_back(i);
                tot += net;
            } else {
                rem = max(rem, 1ll * trx[i][0]);
            }
        }
        ll ans = 0;
        if (rem >= 0) {
            ans = max(ans, rem + tot);
        }
        for (int i = 0; i < idx.size(); i++) {
            ll tmp = tot - (trx[idx[i]][0] - trx[idx[i]][1]) + max(rem, 1ll * trx[idx[i]][0]);
            ans = max(ans, tmp);
        }
        return ans;
    }
};