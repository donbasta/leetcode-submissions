class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        char cur = s[0];
        int len = 1;
        map<pair<int, int>, int> cnt;
        for (int i = 1; i < n; i++) {
            if (s[i] == cur) len++;
            else {
                for (int j = 1; j <= len; j++) {
                    cnt[make_pair(j, cur)] += (len - j + 1);
                }
                cur = s[i];
                len = 1;
            }
        }
        for (int j = 1; j <= len; j++) {
            cnt[make_pair(j, cur)] += (len - j + 1);
        }
        int mx = -1;
        for (auto e : cnt) {
            if (e.second >= 3) {
                mx = max(mx, e.first.first);
            }
        }
        return mx;   
    }
};