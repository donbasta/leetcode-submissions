class Solution {
public:
    int minLength(string s) {
        string tmp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            tmp.push_back(s[i]);
            while (tmp.length() >= 2 && (tmp.substr(tmp.length() - 2, 2) == "AB" || tmp.substr(tmp.length() - 2, 2) == "CD")) {
                tmp.pop_back();
                tmp.pop_back();
            }
        }
        return tmp.length();
    }
};