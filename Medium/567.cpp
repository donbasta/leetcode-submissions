class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<int> c1(26);
        for (auto e : s1) {
            c1[e - 'a']++;
        }
        vector<vector<int>> pre(26, vector<int>(n2));
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < 26; j++) {
                pre[j][i] = (i ? pre[j][i - 1] : 0);
            }
            pre[s2[i] - 'a'][i]++;
        }
        for (int i = n1 - 1; i < n2; i++) {
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                ok &= (c1[j] == (pre[j][i] - (i >= n1 ? pre[j][i - n1] : 0)));
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
};