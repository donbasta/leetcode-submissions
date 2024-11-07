class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_map<char, bool>> from;
        for (auto e : mappings) {
            from[e[0]][e[1]] = true;
        }
        int n = s.length(), m = sub.length();
        if (m > n) return false;
        for (int i = 0; i <= n - m; i++) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (sub[j] != s[i + j] && from[sub[j]].find(s[i + j]) == from[sub[j]].end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};