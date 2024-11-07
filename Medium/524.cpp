class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.length();
        string ret;
        int mx = 0;
        for (auto d : dictionary) {
            int ptr = 0;
            bool ok = false;
            for (int i = 0; i < n; i++) {
                if (s[i] == d[ptr]) ++ptr;
                if (ptr == d.size()) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                if (mx < d.size()) {
                    mx = d.size();
                    ret = d;
                } else if (mx == d.size()) {
                    ret = min(ret, d);
                }
            }
        }
        return ret;
    }
};