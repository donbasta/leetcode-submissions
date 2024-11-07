class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26);
        for (auto e : s) cnt[e - 'a']++;
        for (auto e : t) cnt[e - 'a']--;
        int ans = 0;
        for (int i = 0; i < 26; i++) ans += abs(cnt[i]);
        return ans;   
    }
};