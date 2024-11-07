class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                vector<int> pre(n);
                for (int k = 0; k < n; k++) {
                    int dig = s[k] - 'a';
                    pre[k] = ((dig == i) - (dig == j)) + (k ? pre[k - 1] : 0);
                }
                vector<int> mn(n);
                mn[0] = min(0, pre[0]);
                for (int k = 1; k < n; k++) {
                    mn[k] = min(mn[k - 1], pre[k]);
                }
                int last_i = -1, last_j = -1;
                for (int k = 0; k < n; k++) {
                    int dig = s[k] - 'a';
                    if (dig == i) last_i = k;
                    if (dig == j) last_j = k;
                    if (last_i == -1 || last_j == -1) continue;
                    int idx = min(last_i, last_j);
                    int tmp = pre[k] - (idx ? mn[idx - 1] : 0);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};