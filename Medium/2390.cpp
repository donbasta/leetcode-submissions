class Solution {
public:
    string removeStars(string s) {
        string st;
        for (auto c : s) {
            if (c == '*') {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st;
    }
};