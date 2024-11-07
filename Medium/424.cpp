class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ret = 0;
        for (int i = 0; i < 26; i++) {
            vector<int> pref;
            pref.push_back(0);
            int cur = 0;
            int ans = 0;
            char curChar = 'A' + i;
            for (int j = 0; j < n; j++) {
                cur += s[j] != curChar;
                int a = lower_bound(pref.begin(), pref.end(), cur - k) - pref.begin();
                ans = max(ans, j + 1 - a);
                pref.push_back(cur);
            }
            ret = max(ret, ans);
        }
        return ret;
    }
};