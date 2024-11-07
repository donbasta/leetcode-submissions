class Solution {
public:
    int longestSubsequence(string s, int k) {
        int c0 = 0, ans = 0;
        string bk;
        while (k) {
            bk.push_back((char)((k & 1) + '0'));
            k >>= 1;
        }
        reverse(bk.begin(), bk.end());
        int len = bk.length();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int tmp = min(n - i, len - 1);
            int ptr = 0;
            for (int j = i; j < n; j++) {
                if (bk[ptr] == '1' && s[j] == '0') {
                    if (len - 1 - ptr <= n - 1 - j) {
                        tmp = len;
                        break;
                    }
                } else if (bk[ptr] == s[j]) {
                    ptr++;
                    if (ptr == len) {
                        tmp = len;
                        break;
                    }
                }
            }
            // cout << i << ' ' << (c0 + tmp) << '\n';
            ans = max(ans, c0 + tmp);
            c0 += s[i] == '0';
        }
        ans = max(ans, c0);
        return ans;
    }
};