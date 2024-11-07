class Solution {
public:
    string removeDuplicates(string s) {
        string tmp;
        for (auto c : s) {
            if (!tmp.empty() && tmp.back() == c) {
                tmp.pop_back();
            } else {
                tmp.push_back(c);
            }
        }
        return tmp;
    }
};