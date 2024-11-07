class Solution {
public:
    string stringHash(string s, int k) {
        string res;
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            int cur = 0;
            for (auto c : s.substr(i, k)) {
                cur += c - 'a';
                cur %= 26;
            }
            res.push_back((char)(cur + 'a'));
        }
        return res;
    }
};