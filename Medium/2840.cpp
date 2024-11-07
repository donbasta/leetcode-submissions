class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<string> t1(2), t2(2);
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            t1[i & 1].push_back(s1[i]);
            t2[i & 1].push_back(s2[i]);
        }
        for (int i = 0; i < 2; i++) {
            sort(t1[i].begin(), t1[i].end());
            sort(t2[i].begin(), t2[i].end());
        }
        return ((t1[0] == t2[0]) && (t1[1] == t2[1]));
    }
};