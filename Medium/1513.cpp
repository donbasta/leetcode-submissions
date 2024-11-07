class Solution {
public:
    int numSub(string s) {
        const int mod = 1e9 + 7;
        int cur = 0;
        int ans = 0;
        for (auto c : s) {
            if (c == '0') {
                ans = (1ll * ans + 1ll * cur * (cur + 1) / 2) % mod;
                cur = 0;
            }
            else cur++;
        }
        ans = (1ll * ans + 1ll * cur * (cur + 1) / 2) % mod;
        return ans;
    }
};