class Solution {
public:
    bool isValid(string s) {
        vector<char> ve;
        for (auto c : s) {
            if (c == 'a' || c == 'b') ve.push_back(c);
            else if (c == 'c') {
                if (ve.size() >= 2 && ve.back() == 'b' && ve[ve.size() - 2] == 'a') {
                    ve.pop_back();
                    ve.pop_back();
                } else {
                    ve.push_back(c);
                }
            }
        }
        return ve.empty();
    }
};