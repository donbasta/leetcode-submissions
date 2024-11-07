class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> ve(26);
        for (auto c : s) {
            ve[c - 'a']++;
            if (ve[c - 'a'] == 2) return c;
        }
        return '\0';
    }
};