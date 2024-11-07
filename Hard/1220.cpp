class Solution {
public:
    int countVowelPermutation(int n) {
        const long long MOD = 1e9 + 7;
        unordered_map<char, long long> dp[n + 1];
        for (auto c : "aeiou") {if (c == 0) continue; dp[1][c] = 1;}
        for (int i = 2; i <= n; i++) {
            dp[i]['a'] = (dp[i - 1]['e'] + dp[i - 1]['i'] + dp[i - 1]['u']) % MOD;
            dp[i]['e'] = (dp[i - 1]['a'] + dp[i - 1]['i']) % MOD;
            dp[i]['i'] = (dp[i - 1]['e'] + dp[i - 1]['o']) % MOD;
            dp[i]['o'] = (dp[i - 1]['i']) % MOD;
            dp[i]['u'] = (dp[i - 1]['i'] + dp[i - 1]['o']) % MOD;
        }
        long long ans = 0;
        for (auto c : "aeiou") {
            if (c == 0) continue;
            ans = (ans + dp[n][c]) % MOD;
        }
        return (int) ans;
    }
};