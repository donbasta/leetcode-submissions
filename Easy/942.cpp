class Solution {
public:
    vector<int> diStringMatch(string s) {
        int x = count(s.begin(), s.end(), 'D');
        int l1 = x, l2 = x;
        vector<int> ret;
        ret.push_back(l1);
        for (auto c : s) {
            if (c == 'I') {
                ret.push_back(++l2);
            } else {
                ret.push_back(--l1);
            }
        }
        return ret;
    }
};