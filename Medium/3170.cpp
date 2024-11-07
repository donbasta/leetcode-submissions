class Solution {
public:
    string clearStars(string s) {
        set<pair<char, int>> se;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                se.erase(se.begin());
            } else {
                se.emplace(s[i], -i);
            }
        }
        vector<pair<int, char>> ve;
        for (auto ss : se) {
            ve.emplace_back(-ss.second, ss.first);
        }
        sort(ve.begin(), ve.end());
        string ret;
        for (auto e : ve) {
            ret.push_back(e.second);
        }
        return ret;
    }
};