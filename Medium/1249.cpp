class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string tmp;
        int lol = 0;
        for (auto c : s) {
            if (c == '(') {
                tmp.push_back(c);
                lol++;
            } else if (c == ')') {
                lol--;
                if (lol >= 0) {
                    tmp.push_back(c);
                } else {
                    lol++;
                }
            } else {
                tmp.push_back(c);
            }
        }

        string ans;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            if (tmp[i] == '(') {
                if (lol > 0) {
                    lol--;
                } else {
                    ans.push_back('(');
                }
            } else {
                ans.push_back(tmp[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};