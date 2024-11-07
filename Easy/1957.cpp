class Solution {
public:
    string makeFancyString(string s) {
        int cur = 0;
        char c = '\0';
        string ret;
        for (auto e : s) {
            if (e == c) cur++;
            else if (e != c) {
                cur = 1;
                c = e;
            }
            if (cur >= 3) continue;
            else ret.push_back(e);
        }
        return ret;
    }
};