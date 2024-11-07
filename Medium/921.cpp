class Solution {
public:
    int minAddToMakeValid(string s) {
        int tmp = 0, ret = 0;
        int mn = INT_MAX;
        for (auto c : s) {
            if (c == '(') tmp++;
            else tmp--;
            mn = min(mn, tmp);
        }
        if (mn < 0) ret -= mn, tmp -= mn;
        if (tmp > 0) ret += tmp;
        return ret;
    }
};