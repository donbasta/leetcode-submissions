class Solution {
public:
    bool checkString(string s) {
        string cs = s;
        sort(cs.begin(), cs.end());
        return s == cs;
    }
};