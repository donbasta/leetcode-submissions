class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string, int> cnt;
        for (auto e : arr) {
            int len = e.length();
            for (int i = 0; i < len; i++) {
                for (int j = i; j < len; j++) {
                    cnt[e.substr(i, j - i + 1)]++;
                }
            }
        }
        vector<string> ret;
        for (auto e : arr) {
            string ans;
            unordered_map<string, int> tmp;
            int len = e.length();
            for (int i = 0; i < len; i++) {
                for (int j = i; j < len; j++) {
                    tmp[e.substr(i, j - i + 1)]++;
                }
            }
            for (int i = 0; i < len; i++) {
                for (int j = i; j < len; j++) {
                    if (tmp[e.substr(i, j - i + 1)] == cnt[e.substr(i, j - i + 1)]) {
                        if (ans == "") ans = e.substr(i, j - i + 1);
                        else if (ans.length() > j - i + 1) ans = e.substr(i, j - i + 1);
                        else if (ans.length() == j - i + 1) ans = min(ans, e.substr(i, j - i + 1));
                    }
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};