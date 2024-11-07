class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> hehe;
        for (auto c : s) {
            if (c == '(') {
                string empty;
                hehe.push_back(empty);
            } else if (c == ')') {
                string lol = hehe.back();
                hehe.pop_back();
                reverse(lol.begin(), lol.end());
                if (hehe.empty()) {
                    string empty;
                    hehe.push_back(empty);
                }
                hehe.back().append(lol);
            } else {
                if (hehe.empty()) {
                    string empty;
                    hehe.push_back(empty);
                }
                hehe.back().push_back(c);
            }
        }
        return hehe.back();
    }
};