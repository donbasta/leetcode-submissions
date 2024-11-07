class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s.length(); i++) cnt[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++) cnt[t[i] - 'a']--;
        int ans = 0;
        for (int i = 0; i < 26; i++) ans += max(0, cnt[i]);
        return ans;
    }
};