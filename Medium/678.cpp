class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, star = 0;
        for (auto c : s) {
            left += c == '(';
            right += c == ')';
            star += c == '*';
        }
        if (star < abs(left - right)) return false;
        int star1 = star;
        if ((star + left + right) & 1) star1--;
        int need_left = (right - left + star1) / 2;
        int need_right = (left - right + star1) / 2;
        int sz = s.length();
        vector<int> pos;
        for (int i = 0; i < sz; i++) {
            if (s[i] == '*') pos.emplace_back(i);
        }
        assert (pos.size() == star);
        for (int i = 0; i < need_left; i++) {
            s[pos[i]] = '(';
        }
        for (int i = star - 1; i >= star - need_right; i--) {
            s[pos[i]] = ')';
        }
        int pref = 0;
        for (auto c : s) {
            if (c == '(') pref++;
            else if (c == ')') pref--;
            else if (c == '*') continue;
            if (pref < 0) return false;
        }
        return true;
    }
};