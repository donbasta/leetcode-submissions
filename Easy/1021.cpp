class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int cur = 0;
        vector<int> pos;
        pos.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cur++;
            else cur--;
            if (cur == 0) {
                pos.push_back(i);
            }
        }
        int sz = pos.size();
        string ret;
        for (int i = 0; i < sz - 1; i++) {
            ret += s.substr(pos[i] + 2, pos[i + 1] - pos[i] - 2);
        }
        return ret;
    }
};