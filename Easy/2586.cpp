class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        auto is_vowel = [&](char c) -> bool {
            for (auto x : "aeiou") {
                if (x == c) return true;
            }
            return false;
        };
        for (int i = left; i <= right; i++) {
            if (is_vowel(words[i][0]) && is_vowel(words[i].back())) {
                ans++;
            }
        }
        return ans;
    }
};