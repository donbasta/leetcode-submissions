class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string tmp;
        for (auto w : words) {
            tmp += w;
            if (tmp == s) return true;
        }
        return false;
    }
};