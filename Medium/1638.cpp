class Solution {
public:
    int countSubstrings(string s, string t) {
        int lmao = min(s.length(), t.length());
        int ans = 0;
        for (int len = 1; len <= lmao; len++) {
            for (int i = 0; i + len - 1 < s.size(); i++) {
                for (int j = 0; j + len - 1 < t.size(); j++) {
                    int tmp = 0;
                    for (int k = 0; k < len; k++) {
                        tmp += (s[i + k] != t[j + k]);
                    }
                    ans += (tmp == 1);
                }
            }
        }
        return ans;
    }
};