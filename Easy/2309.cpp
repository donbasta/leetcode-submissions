class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> L(26), U(26);
        string ret;
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') L[c - 'a'] = true;
            else U[c - 'A'] = true;
        }
        for (int i = 25; i >= 0; i--) {
            if (L[i] && U[i]) {
                ret.push_back((char)(i + 'A'));
                return ret;
            }
        }
        return ret;
    }
};