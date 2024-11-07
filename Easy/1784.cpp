class Solution {
public:
    bool checkOnesSegment(string s) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        while (!s.empty() && s.back() == '1') s.pop_back();
        return count(s.begin(), s.end(), '1') == 0;
    }
};