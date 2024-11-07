class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> pre(26, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                pre[j][i] = (i ? pre[j][i - 1] : 0);
            }
            pre[s[i] - 'a'][i]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + k - 1; j < n; j++) {
                bool ok = false;
                for (int t = 0; t < 26; t++) {
                    int cnt = pre[t][j] - (i ? pre[t][i - 1] : 0);
                    if (cnt >= k) {
                        ok = true;
                        break;
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};