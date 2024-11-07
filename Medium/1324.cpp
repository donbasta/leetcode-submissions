class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string tmp;
        tmp.push_back(s[0]);
        int n = s.length();
        int sz = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ' ') {
                sz = max(sz, (int)tmp.length());
                words.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(s[i]);
            }
        }
        sz = max(sz, (int)tmp.length());
        words.push_back(tmp);
        vector<string> ret(sz);
        for (auto w : words) {
            for (int i = 0; i < w.length(); i++) {
                ret[i].push_back(w[i]);
            }
            for (int i = w.length(); i < sz; i++) {
                ret[i].push_back(' ');
            }
        }
        for (auto& w : ret) {
            while (w.back() == ' ') w.pop_back();
        }
        return ret;
    }
};