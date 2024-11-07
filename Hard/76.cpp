class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
 
        int mn = INT_MAX;
        int start = -1;
        unordered_map<char, int> cns, cnt;
        for (auto e : t) cnt[e]++;
        int r = 0;
        cns[s[r]]++;

        const function<bool()> ok = [&]() -> bool {
            bool okay = true;
            for (auto c : cnt) {
                okay &= cns[c.first] >= c.second;
            }
            return okay;
        };

        for (int i = 0; i < m; i++) {
            while(!ok() && (r < m - 1)) {
                r++;
                cns[s[r]]++;
            }
            if (ok()) {
                if (r - i + 1 < mn) {
                    mn = r - i + 1;
                    start = i;
                }
            } else {
                break;
            }
            cns[s[i]]--;
        }
        if (mn == INT_MAX) return "";
        return s.substr(start, mn);
    }
};