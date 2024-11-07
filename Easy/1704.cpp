class Solution {
public:
    bool isVowel(char c) {
        for (auto cc : "aeiouAEIOU") {
            if (c == cc) return true;
        }
        return false;
    }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int tmp = 0;
        for (int i = 0; i < n / 2; i++) {
            tmp += isVowel(s[i]);
        }
        for (int i = n / 2; i < n; i++) {
            tmp -= isVowel(s[i]);
        }
        return tmp == 0;
    }
};