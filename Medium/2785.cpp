class Solution {
public:
    string sortVowels(string s) {
        const function<bool(char)> is_vowel = [&](char c) -> bool {

            return (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O');  

        };

        int n = s.length();

        string vowels;

        vector<int> indices;

        for (int i = 0; i < n; i++) {

            if (is_vowel(s[i])) {

                indices.push_back(i);

                vowels.push_back(s[i]);

            }

        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < vowels.length(); i++) {

            s[indices[i]] = vowels[i];

        }

        return s;
    }
};