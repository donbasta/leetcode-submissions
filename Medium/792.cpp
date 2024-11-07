class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int ans = 0;

        int fi[26], nx[n][26];
        for (int i = 0; i < 26; i++) fi[i] = n;
        for (int i = 0; i < n; i++) for (int j = 0; j < 26; j++) nx[i][j] = n;

        for (int i = n - 1; i >= 0; i--) {
            fi[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = n - 2; j >= 0; j--) {
                if (s[j + 1] - 'a' == i) nx[j][i] = j + 1;
                else nx[j][i] = nx[j + 1][i];
            }
        }
    
        for (int i = 0; i < m; i++) {
            int cur = fi[words[i][0] - 'a'];
            if (cur == n) continue;
            int idx = 1;
            while (idx < words[i].length()) {
                cur = nx[cur][words[i][idx] - 'a'];
                if (cur == n) break;
                idx++;
            }
            if (idx == words[i].length()) ans++;
        }

        return ans;
    }
};