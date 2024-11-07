class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        map<char, vector<int>> pos;
        for (auto c : s) {
            pos[c].emplace_back(len++);
        }
        set<char> se;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            se.insert(s[i]);
            int lim = -1;
            for (auto c : se) {
                int x = upper_bound(pos[c].begin(), pos[c].end(), i) - pos[c].begin();
                if (x >= 2) {
                    lim = max(lim, pos[c][x - 2] + 1);
                } else {
                    lim = max(lim, 0);
                }
            }
            ans = max(ans, i - lim + 1);
        }
        return ans;
    }
};