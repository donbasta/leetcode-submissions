class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        using ll = long long;
        vector<ll> ans(n);
        if (x > y) swap(x, y);
        if (x == y || x + 1 == y) {
            for (int i = 0; i < n; i++) {
                ans[i] = 2 * (n - 1 - i);
            }
            return ans;
        }
        for (int i = 0; i < x - 2; i++) {
            ans[i] += x - 2 - i;
        }
        for (int i = 0; i < n - y - 1; i++) {
            ans[i] += n - y - 1 - i;
        }
        int cnt = y - x + 1;
        for (int i = 0; i < cnt / 2; i++) {
            if ((cnt % 2 == 0) && (i == cnt / 2 - 1)) {
                ans[i] += cnt / 2;
            } else {
                ans[i] += cnt;
            }
        }
        int L = x - 2, R = n - y - 1;
        if (L >= 0 && R >= 0) {
            for (int i = 2; i < n - y + x; i++) {
                int need = i - 2;
                int u = min(need, L);
                int v = max(0, need - R);
                if (u >= v) ans[i] += (u - v + 1);
            }
        }
        vector<ll> t1(n + 1), t2(n + 1);
        for (int i = 0; i <= cnt / 2; i++) {
            int L = i, R = i + x - 2;
            int mul = 2;
            if (i == 0 || (2 * i == cnt)) mul = 1;
            t1[L] += mul;
            t1[R + 1] -= mul;
        }
        for (int i = 0; i <= cnt / 2; i++) {
            int L = i, R = i + n - y - 1;
            int mul = 2;
            if (i == 0 || (2 * i == cnt)) mul = 1;
            t2[L] += mul;
            t2[R + 1] -= mul;
        }
        for (int i = 1; i < n; i++) t1[i] += t1[i - 1], t2[i] += t2[i - 1];
        for (int i = 0; i < n; i++) ans[i] += t1[i] + t2[i];
        for (int i = 0; i < n; i++) ans[i] *= 2;
        return ans;
    }
};