class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ns;
        for (auto c : s) {
            if (c == '#') {
                if (!ns.empty()) ns.pop_back();
            } else {
                ns.push_back(c);
            }
        }
        string nt;
        for (auto c : t) {
            if (c == '#') {
                if (!nt.empty()) nt.pop_back();
            } else {
                nt.push_back(c);
            }
        }
        return ns == nt;
    }
};