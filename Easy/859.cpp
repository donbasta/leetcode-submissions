class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if (n != goal.length()) return false;
        vector<int> pos;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) {
                pos.push_back(i);
            } else {
                cnt[s[i] - 'a']++;
            }
        }
        if (pos.size() == 0) {
            int mx = 0;
            for (int i = 0; i < 26; i++) mx = max(mx, cnt[i]);
            return mx >= 2;
        }
        if (pos.size() != 2) {
            return false;
        }
        if (s[pos[0]] != goal[pos[1]]) return false;
        if (s[pos[1]] != goal[pos[0]]) return false;
        return true;
    }
};