class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') pre[i + 1] = pre[i] + 1;
            else pre[i + 1] = pre[i] - 1;
        }
        map<int, int> runningKiri;
        map<int, int> kanan;
        for (int i = 0; i <= n; i++) {
            kanan[pre[i]] = i;
        }
        int ans = 0;
        runningKiri[pre[n]] = n;
        runningKiri[pre[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int start = pre[i];
            runningKiri[start] = i;
            if (runningKiri.find(start - 1) == runningKiri.end()) {
                if (kanan[start] <= i) {
                    continue;
                } else {
                    ans = max(ans, kanan[start] - i);
                }
            } else {
                ans = max(ans, runningKiri[start - 1] - i - 1);
            }
        }
        return ans;
    }
};