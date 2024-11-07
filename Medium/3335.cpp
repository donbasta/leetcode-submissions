class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        const int MOD = 1e9 + 7;
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<int> tmp(26);
            for (int j = 0; j < 26; j++) {
                if (j == 25) {
                    tmp[0] = (tmp[0] + cnt[j]) % MOD;
                    tmp[1] = (tmp[1] + cnt[j]) % MOD;
                } else {
                    tmp[j + 1] = (tmp[j + 1] + cnt[j]) % MOD;
                }
            }
            cnt.swap(tmp);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + cnt[i]) % MOD;
        }
        return ans;
    }
};