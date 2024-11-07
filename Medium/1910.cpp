class Solution {
public:
    string removeOccurrences(string s, string part) {
        string tmp;
        int n = s.size(), m = part.size();
        for (int i = 0; i < n; i++) {
            tmp.push_back(s[i]);
            int len = (int)tmp.length();
            if (len >= m && tmp.substr(len - m, m) == part) {
                for (int j = 0; j < m; j++) tmp.pop_back();
            }
        }
        return tmp;
    }
};