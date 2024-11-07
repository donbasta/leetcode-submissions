class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        unordered_map<string, int> freq;
        for (int len = minSize; len <= maxSize; len++) {
            vector<int> cnt(26);
            int dis = 0;
            for (int i = 0; i < len - 1; i++) {
                if (cnt[s[i] - 'a'] == 0) dis++;
                cnt[s[i] - 'a']++;
            }
            for (int i = len - 1; i < n; i++) {
                if (cnt[s[i] - 'a'] == 0) dis++;
                cnt[s[i] - 'a']++;
                if (dis <= maxLetters) {
                    freq[s.substr(i - len + 1, len)]++;
                }
                cnt[s[i - len + 1] - 'a']--;
                if (cnt[s[i - len + 1] - 'a'] == 0) dis--;
            }
        }
        int ans = 0;
        for (auto e : freq) {
            ans = max(ans, e.second);
        }
        return ans;
    }
};