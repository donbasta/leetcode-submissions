class Solution {
public:
    string toLowerCase(string s) {
        string ret;
        for (auto c : s) {
            char nx = c;
            if (c >= 'A' && c <= 'Z') {
                nx = c + 'a' - 'A';
            }
            ret.push_back(nx);
        }
        return ret;
    }
};