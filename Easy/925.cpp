class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        auto compress = [&](string& s) -> vector<pair<char, int>> {
            int sz = s.size();
            int len = 1;
            vector<pair<char, int>> ve;
            for (int i = 1; i < sz; i++) {
                if (s[i] == s[i - 1]) {
                    len++;
                } else {
                    ve.emplace_back(s[i - 1], len);
                    len = 1;
                }
            }
            ve.emplace_back(s.back(), len);
            return ve;
        };

        vector<pair<char, int>> cn = compress(name);
        vector<pair<char, int>> ct = compress(typed);
        if (cn.size() != ct.size()) return false;
        int n = cn.size();
        for (int i = 0; i < n; i++) {
            if (cn[i].first != ct[i].first) return false;
            if (cn[i].second > ct[i].second) return false;
        }
        return true;
    }
};