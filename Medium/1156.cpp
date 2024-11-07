class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        if (n == 1) return 1;
        vector<int> cnt(26);
        for (auto c : text) cnt[c - 'a']++;
        vector<pair<int, char>> le(n), ri(n);
        le[0] = make_pair(0, '?');
        for (int i = 1; i < n; i++) {
            if (i >= 2 && text[i - 1] == text[i - 2]) {
                le[i] = make_pair(le[i - 1].first + 1, le[i - 1].second);
            } else {
                le[i] = make_pair(1, text[i - 1]);
            }
        }
        ri[n - 1] = make_pair(0, '?');
        for (int i = n - 2; i >= 0; i--) {
            if (i + 2 < n && text[i + 1] == text[i + 2]) {
                ri[i] = make_pair(ri[i + 1].first + 1, ri[i + 1].second);
            } else {
                ri[i] = make_pair(1, text[i + 1]);
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (le[i].second == ri[i].second) {
                if (le[i].first + ri[i].first < cnt[le[i].second - 'a']) {
                    ans = max(ans, le[i].first + ri[i].first + 1);
                } else {
                    ans = max(ans, le[i].first + ri[i].first);
                }
            } else {
                if (le[i].second != '?' && le[i].first < cnt[le[i].second - 'a']) {
                    ans = max(ans, le[i].first + 1);
                } else {
                    ans = max(ans, le[i].first);
                }
                if (ri[i].second != '?' && ri[i].first < cnt[ri[i].second - 'a']) {
                    ans = max(ans, ri[i].first + 1);
                } else {
                    ans = max(ans, ri[i].first);
                }
            }
        }
        return ans;
    }
};