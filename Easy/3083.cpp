class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();
        set<string> se;
        for (int i = 0; i < n - 1; i++) {
            se.insert(s.substr(i, 2));
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < n - 1; i++) {
            if (se.count(s.substr(i, 2))) return true;
        }
        return false;
    }
};