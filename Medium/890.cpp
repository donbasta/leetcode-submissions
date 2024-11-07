class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.length();
        vector<string> ans;
        for (auto s : words) {
            vector<int> mp(26, -1);
            vector<bool> alr(26, false);
            bool can = true;
            for (int i = 0; i < n; i++) {
                if (mp[pattern[i] - 'a'] != -1) {
                    if (mp[pattern[i] - 'a'] != s[i] - 'a') {
                        can = false;
                        break;
                    }
                } else {
                    if (alr[s[i] - 'a']) {
                        can = false;
                        break;
                    }
                    mp[pattern[i] - 'a'] = s[i] - 'a';
                    alr[s[i] - 'a'] = true;
                }
            }
            if (can) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};