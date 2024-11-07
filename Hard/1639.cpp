class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int l1 = words[0].length(), l2 = target.length();
        const int MOD = 1e9 + 7;
        int sdp[l1 + 1][l2 + 1];
        int cnt[l1][26];
        memset(sdp, 0, sizeof(sdp));
        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i][words[j][i] - 'a']++;
            }
        }

        for (int i = 0; i <= l1; i++) sdp[i][l2] = 1;

        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                int tmp = (1ll * cnt[i][(target[j] - 'a')] * sdp[i + 1][j + 1]) % MOD;
                sdp[i][j] = (sdp[i + 1][j] + tmp) % MOD;
            }
        }

        return sdp[0][0];
    }
};