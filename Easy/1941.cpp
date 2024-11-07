class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> cnt(26);
        for (auto c : s) cnt[c - 'a']++;
        set<int> se;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                se.insert(cnt[i]);
            }
        }
        return se.size() == 1;
    }
};