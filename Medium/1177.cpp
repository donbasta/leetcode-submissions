class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        bool cnt[26][n];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[j][i] = (s[i] - 'a' == j) ^ (i ? cnt[j][i - 1] : 0);
            }
        }
        vector<bool> ret;
        for (auto e : queries) {
            int odd = 0;
            for (int i = 0; i < 26; i++) {
                bool tmp = cnt[i][e[1]] ^ (e[0] ? cnt[i][e[0] - 1] : 0);
                odd += tmp;
            }
            ret.push_back(odd <= (e[2] * 2 + 1));
        }
        return ret;
    }
};