class Solution {
public:
    int countVowelSubstrings(string word) {
        map<char, int> mp;
        int ans = 0;
        int idx = 0;
        int start_vowel = -1;
        const function<bool(char)> is_vowel = [&](char x) -> bool {
            for (auto c : "aeiuo") if (x == c) return true;
            return false;
        };
        for (auto c : word) {
            if (is_vowel(c)) {
                if (start_vowel == -1) start_vowel = idx;
                mp[c] = idx;
                if (mp.size() == 5) {
                    int mn = 1e9;
                    for (auto e : mp) mn = min(mn, e.second);
                    ans += (mn - start_vowel + 1);
                }
            } else {
                mp.clear();
                start_vowel = -1;
            }
            idx++;
        }
        return ans;
    }
};