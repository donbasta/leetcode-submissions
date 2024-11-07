class Solution {
public:
    string finalString(string s) {
        string ret;
        for (auto c : s) {
            if (c != 'i') ret.push_back(c);
            else reverse(ret.begin(), ret.end());
        }
        return ret;
    }
};