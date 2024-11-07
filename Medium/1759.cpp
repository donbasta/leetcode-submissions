class Solution {
public:
    int countHomogenous(string s) {
        const int mod = 1e9 + 7;
        int ans = 0;
        int len = 1;
        char cur = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == cur) len++;
            else {
                ans = (1ll * ans + 1ll * len * (len + 1) / 2) % mod;
                len = 1;
                cur = s[i];
            }
        }
        ans = (1ll * ans + 1ll * len * (len + 1) / 2) % mod;
        return ans;
    }
};