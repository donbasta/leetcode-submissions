class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
            
        int n = nums.size();
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        unordered_map<int, int> pos;
        int mx = 0;
        for (auto p : primes) pos[p] = mx++;
        
        vector<int> dp((1 << mx) + 5, 1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int c = nums[i];
            int mask = 0;
            bool squarefree = true;
            for (int j = 2; j * j <= c; j++) {
                if (c % j != 0) continue;
                int pw = 0;
                while (c % j == 0) {
                    pw++, c /= j;
                }
                if (pw > 1) {
                    squarefree = false;
                    break;
                }
                mask ^= (1 << pos[j]);
            }
            if (!squarefree) continue;
            if (c > 1) {
                mask ^= (1 << pos[c]);
            }
            
            ans = (ans + dp[mask]) % MOD;
            for (int j = 0; j < (1 << mx); j++) {
                if ((j & mask) == 0) {
                    dp[j] = (dp[j] + dp[j ^ mask]) % MOD;
                }
            }
        }
        
        ans %= MOD;
        return ans;
    }
};