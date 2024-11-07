class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (pos[i].empty()) continue;
            int sz = pos[i].size();
            for (int j = 0; j < sz; j++) {
                int kiri = pos[i][j] - (j ? (pos[i][j - 1] + 1) : 0) + 1;
                int kanan = ((j == sz - 1) ? n : pos[i][j + 1]) - pos[i][j];
                ans += kiri * kanan;
            }
        }
        return ans;
    }
};