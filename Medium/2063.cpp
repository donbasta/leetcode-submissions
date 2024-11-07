class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long ans = 0;
        auto is_vowel = [&](char c) -> bool {
            int x = c - 'a';
            return (x == 0) || (x == 4) || (x == 8) || (x == 14) || (x == 20);
        };
        for (int i = 0; i < n; i++) {
            if (is_vowel(word[i])) {
                ans += 1ll * (i + 1) * (n - i);
            }
        }
        return ans;
    }
};