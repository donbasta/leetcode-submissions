class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int l = 1, r = n, ans = -1;

        vector<int> pq(n), pw(n), pe(n), pr(n);
        for (int i = 0; i < n; i++) {
            pq[i] = (i ? pq[i - 1] : 0);
            pw[i] = (i ? pw[i - 1] : 0);
            pe[i] = (i ? pe[i - 1] : 0);
            pr[i] = (i ? pr[i - 1] : 0);
            char c = s[i];
            if (c == 'Q') pq[i]++;
            else if (c == 'E') pe[i]++;
            else if (c == 'W') pw[i]++;
            else if (c == 'R') pr[i]++;
        }

        int Q = pq.back(), W = pw.back(), E = pe.back(), R = pr.back();
        if (Q == W && W == E && E == R) return 0;

        auto ok = [&](int len) -> bool {
            for (int i = 0; i <= n - len; i++) {
                int cq = Q - pq[i + len - 1] + ((i > 0) ? pq[i - 1] : 0);
                int cw = W - pw[i + len - 1] + ((i > 0) ? pw[i - 1] : 0);
                int ce = E - pe[i + len - 1] + ((i > 0) ? pe[i - 1] : 0);
                int cr = R - pr[i + len - 1] + ((i > 0) ? pr[i - 1] : 0);
                int mx = max({cq, cw, ce, cr});
                int need = 4 * mx - (cq + cw + ce + cr);
                if (len >= need) return true;
            }
            return false;
        };

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};