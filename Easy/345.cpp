class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        vector<int> vowels;
        auto is_vowel = [&](char c) -> bool {
            for (auto tmp : "aeiuoAEIOU") {
                if (c == tmp) return true;
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            if (is_vowel(s[i])) vowels.push_back(i);
        }
        int sz = vowels.size();
        for (int i = 0; i < sz / 2; i++) {
            swap(s[vowels[i]], s[vowels[sz - 1 - i]]);
        }
        return s;
    }
};