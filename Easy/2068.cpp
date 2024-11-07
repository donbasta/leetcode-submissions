class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int f[26];
        memset(f, 0, sizeof(f));
        for (auto c : word1) f[c - 'a']++;
        for (auto c : word2) f[c - 'a']--;
        for (int i = 0; i < 26; i++) {
            if (abs(f[i]) > 3) return false;
        }
        return true;
    }
};