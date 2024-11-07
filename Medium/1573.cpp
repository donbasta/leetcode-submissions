class Solution {
public:
    int numWays(string s) {
        int cnt = 0, n = s.length();
        for (auto c : s) cnt += c == '1';
        if (cnt % 3 != 0) return 0;
        const long long MOD = 1e9 + 7;
        if (cnt == 0) {
            return (1ll * (n - 1) * (n - 2) / 2) % MOD;
        }
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') pos.push_back(i);
        }
        int a = pos[cnt / 3] - pos[cnt / 3 - 1];
        int b = pos[cnt / 3 * 2] - pos[cnt / 3 * 2 - 1];
        return (1ll * a * b) % MOD;
    }
};