class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == "") return true;
        int ns = 0;
        for (int i = 0; i < (int)t.size(); i++) {
            if (t[i] == s[ns]) {
                ns++;
            }
            if (ns == (int)s.size()) return true;
        }
        return false;
    }
};