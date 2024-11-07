class Solution {
public:
    string smallestSubsequence(string s) {
        string ret;
        int n = s.length();
        vector<bool> ada(26);
        vector<vector<int>> cnt(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) cnt[i + 1][j] = cnt[i][j];
            cnt[i + 1][s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (ada[s[i] - 'a']) continue;
            while (!ret.empty() && (ret.back() >= s[i]) && (cnt[n][ret.back() - 'a'] - cnt[i][ret.back() - 'a'] > 0)) {
                ada[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret.push_back(s[i]);
            ada[s[i] - 'a'] = true;
        }
        return ret;
    }
};