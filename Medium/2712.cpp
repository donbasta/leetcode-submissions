class Solution {
public:
    long long minimumCost(string s) {
        using ll = long long;
        int n = s.length();
        int prv = -1;
        vector<ll> pre(n), suf(n), L(n, -1), R(n, n);
        for (int i = 0; i < n; i++) {
            pre[i] = (i + 1) + (prv >= 0 ? pre[prv] : 0);
            L[i] = prv;
            if (i < n - 1 && s[i + 1] != s[i]) prv = i;
        }
        prv = n;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = (n - i) + (prv < n ? suf[prv] : 0);
            R[i] = prv;
            if (i > 0 && s[i - 1] != s[i]) prv = i; 
        }
        ll ans = 1e18;
        for (int i = 0; i < n; i++) {
            ll tmp = (L[i] >= 0 ? pre[L[i]] : 0) + (R[i] < n ? suf[R[i]] : 0);
            // cout << i << ' ' << tmp << ' ' << L[i] << ' ' << R[i] << '\n';
            ans = min(ans, tmp);
        }
        return ans;
    }
};