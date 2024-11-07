class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> pd(n, vector<bool>(n));
        for (int i = 0; i < n; i++) pd[i][i] = true;
        for (int i = 0; i < n - 1; i++) if (s[i] == s[i + 1]) pd[i][i + 1] = true;
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                if ((s[i] == s[i + len - 1]) && pd[i + 1][i + len - 2]) pd[i][i + len - 1] = true;
            }
        }
        vector<vector<vector<string>>> parts(n);
        parts[0].push_back(vector<string>{s.substr(0, 1)});
        for (int i = 1; i < n; i++) {
            if (pd[0][i]) parts[i].push_back(vector<string>{s.substr(0, i + 1)});
            for (int j = i; j >= 1; j--) {
                if (!pd[j][i]) continue;
                string tmp = s.substr(j, i - j + 1);
                for (auto P : parts[j - 1]) {
                    P.push_back(tmp);
                    parts[i].push_back(P);
                }
            }
        }
        return parts.back();
    }
};