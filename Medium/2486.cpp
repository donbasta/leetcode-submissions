class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0;
        for (auto c : s) {
            if (c == t[idx]) idx++;
            if (idx == t.length()) return 0;
        }
        return t.length() - idx;
    }
};