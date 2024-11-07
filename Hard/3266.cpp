class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int M) {
        int n = nums.size();
        using  ll = long long;
        vector<ll> ar(n);
        vector<int> ret(n);
        for (int i = 0; i < n; i++) ar[i] = nums[i];
        const int MOD = 1e9 + 7;

        if (M == 1) return nums;

        auto fpow = [&](ll a, ll b) -> ll {
            ll ret = 1;
            while (b) {
                if (b & 1) ret = (ret * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };

        ll mx = 0;
        int pos_mx = -1;
        map<ll, set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[ar[i]].insert(i);
            if (ar[i] >= mx) {
                mx = ar[i];
                pos_mx = i;
            }
        }
        int j = 0;
        while (true) {
            ll val = mp.begin()->first;
            assert (!mp[val].empty());
            int pos = *mp[val].begin();
            ar[pos] *= M;
            mp[val].erase(pos);
            mp[ar[pos]].insert(pos);
            if (mp[val].empty()) {
                mp.erase(val);
            }
            j++;
            if (j == k) {
                break;
            }
            if (pos == pos_mx) {
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            ret[i] = (ar[i] % MOD);
        }
        if (j == k) {
            return ret;
        }
        int times = (k - j) / n;
        int sisa = k - (j + times * n);
        ll pw = fpow(M, times);
        for (int i = 0; i < n; i++) {
            ret[i] = (1ll * ret[i] * pw) % MOD;
        }
        for (int i = 0; i < sisa; i++) {
            ll val = mp.begin()->first;
            int pos = *mp[val].begin();
            ret[pos] = (1ll * ret[pos] * M) % MOD;
            mp[val].erase(pos);
            if (mp[val].empty()) {
                mp.erase(val);
            }
        }
        return ret;
    }
};