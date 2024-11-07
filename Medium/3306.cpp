class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        using ll = long long;
        int n = word.size();
        ll ans = 0;

        int id[26], last[5];
        memset(id, -1, sizeof(id));
        memset(last, -1, sizeof(last));
        id[0] = 0;
        id[4] = 1;
        id[8] = 2;
        id[14] = 3;
        id[20] = 4;

        int pref[n];
        memset(pref, 0, sizeof(pref));

        for (int i = 0; i < n; i++) {
            int cur = word[i] - 'a';
            pref[i] = (i ? pref[i - 1] : 0);
            if (id[cur] != -1) {
                last[id[cur]] = i;
            } else {
                pref[i]++;
            }
            int T = INT_MAX;
            for (int j = 0; j < 5; j++) {
                T = min(T, last[j]);
            }
            if (T == -1) continue;
            int L = - 1, R = -1;
            int lo = 0, hi = T;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int cons = pref[i] - (mid ? pref[mid - 1] : 0);
                if (cons < k) {
                    hi = mid - 1;
                } else {
                    R = mid;
                    lo = mid + 1;
                }
            }
            lo = 0, hi = T;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int cons = pref[i] - (mid ? pref[mid - 1] : 0);
                if (cons > k) {
                    lo = mid + 1;
                } else {
                    L = mid;
                    hi = mid - 1;
                }
            }
            // cout << i << ' ' << L << ' ' << R << '\n';
            if (L != -1 && R != -1) {
                ans += (R - L + 1);
            }
        }
        return ans;
    }
};