class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> se;
        int n = s.length();
        for (int i = 0; i + k - 1 < n; i++) {
            se.insert(s.substr(i, k));
        }
        return (se.size() == (1 << k));
    }
};