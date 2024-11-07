class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<vector<int>> L(n + 2, vector<int>(26));
        vector<vector<int>> R(n + 2, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) L[i + 1][j] = L[i][j];
            L[i + 1][s[i] - 'a']++;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) R[i + 1][j] = R[i + 2][j];
            R[i + 1][s[i] - 'a']++;
        }
        int ans = 0;
        vector<vector<bool>> ada(26, vector<bool>(26));
        for (int i = 2; i <= n - 1; i++) {
            for (int j = 0; j < 26; j++) {
                if (L[i - 1][j] > 0 && R[i + 1][j] > 0) {
                    ada[s[i - 1] - 'a'][j] = true;
                }
            }
        }
        for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) ans += ada[i][j];
        return ans;
    }
};