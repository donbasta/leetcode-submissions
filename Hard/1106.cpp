class Solution {
public:
    bool parseBoolExpr(string exp) {
        int itr = 0;
        int len = exp.length();
        vector<vector<bool>> ve;
        vector<char> op;
        ve.push_back(vector<bool>());
        op.push_back('\0');
        while (itr < len) {
            char c = exp[itr];
            if (c == '!' || c == '&' || c == '|') {
                ve.push_back(vector<bool>());
                op.push_back(c);
                assert(exp[itr + 1] == '(');
                itr += 2;
            } else if (c == ')') {
                bool val;
                if (op.back() == '|') {
                    val = false;
                    for (auto b : ve.back()) val = (val || b);
                } else if (op.back() == '&') {
                    val = true;
                    for (auto b : ve.back()) val = (val && b);
                } else if (op.back() == '!') {
                    assert (ve.back().size() == 1);
                    val = !ve.back()[0];
                }
                ve.pop_back();
                op.pop_back();
                ve.back().push_back(val);
                itr++;
            } else if (c == 'f') {
                ve.back().push_back(false);
                itr++;
            } else if (c == 't') {
                ve.back().push_back(true);
                itr++;
            } else if (c == ',') {
                itr++;
            }
        }
        return ve[0][0];
    }
};