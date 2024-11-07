class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> freq(26);
        for (auto c : chars) {
            freq[c - 'a']++;
        }
        for (auto w : words) {
            vector<int> cnt(26);
            for (auto c : w) {
                cnt[c - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                ok &= (cnt[i] <= freq[i]);
            }
            if (ok) {
                ans += w.length();
            }
        }
        return ans;
    }
};