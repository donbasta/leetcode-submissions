class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.length() < b.length();
        });
        unordered_map<string, bool> bisa;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int len = words[i].length();
            if (len == 1) {
                bisa[words[i]] = true;
            } else {
                if (bisa.count(words[i].substr(0, len - 1))) {
                    bisa[words[i]] = true;
                }
            }
        }
        string ret;
        int mx = 0;
        for (auto e : bisa) {
            int len = e.first.length();
            if (len > mx) {
                mx = e.first.length();
                ret = e.first;
            } else if (len == mx) {
                ret = min(ret, e.first);
            }
        }
        return ret;
    }
};