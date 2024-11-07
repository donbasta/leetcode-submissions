class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> cnt(3), ptr(3, n + 1), cntr(3);
        int ans = n + 1;

        for (int i = 0; i < 3; i++) {
            if (count(s.begin(), s.end(), 'a' + i) < k) return -1;
            int tmp = 0;
            for (int j = n - 1; j >= 0; j--) {
                tmp += s[j] - 'a' == i;
                if (tmp == k) {
                    ptr[i] = j + 1;
                    break;
                }
            }
            cntr[i] = k;
        }

        for (int i = 0; i <= n; i++) { //take first i leftmost characters
            if (i >= 1) cnt[s[i - 1] - 'a']++;
            int suf = n + 1;
            for (int j = 0; j < 3; j++) {
                int need = k - cnt[j];
                if (need <= 0) continue;
                while (cntr[j] + cnt[j] >= k) {
                    if (s[ptr[j] - 1] - 'a' == j) cntr[j]--;
                    ptr[j]++;
                }
                suf = min(suf, ptr[j] - 1);
            }
            ans = min(ans, i + n + 1 - suf);
        }
        return ans;
    }
};