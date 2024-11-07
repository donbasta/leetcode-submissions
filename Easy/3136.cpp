class Solution {
public:
    bool isValid(string word) {
        bool ok = ((int)word.length() >= 3);
        bool vowel = false, consonant = false;
        auto is_digit = [&](char c) -> bool {
            return (c >= '0' && c <= '9');
        };
        auto is_upper = [&](char c) -> bool {
            return (c >= 'A' && c <= 'Z');
        };
        auto is_lower = [&](char c) -> bool {
            return (c >= 'a' && c <= 'z');
        };
        auto is_vowel = [&](char c) -> bool {
            for (auto cc : "aiueoAIUEO") {
                if (cc == c) return true; 
            }
            return false;
        };
        auto is_consonant = [&](char c) -> bool {
            return ((is_upper(c) || is_lower(c)) && !is_vowel(c));
        };
        for (auto c : word) {
            if (!is_digit(c) && !is_upper(c) && !is_lower(c)) {
                return false;
            }
            if (is_vowel(c)) vowel = true;
            if (is_consonant(c)) consonant = true;
        }
        return ok && vowel && consonant;
    }
};