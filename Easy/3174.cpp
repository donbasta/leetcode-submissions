class Solution {
public:
    string clearDigits(string s) {
        string ret;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                ret.pop_back();
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }
};