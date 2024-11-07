class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        const int INF = 2e9;
        unordered_map<int, bool> is_square;
        for (long long i = 0; ; i++) {
            if (i * i > 1ll * INF) break;
            is_square[i * i] = true;
        }
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        vector<int> fc(13);
        fc[0] = 1;
        for (int i = 1; i <= 12; i++) fc[i] = fc[i - 1] * i;
        vector<vector<int>> dp(1 << n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
        }
        for (int i = 1; i < (1 << n); i++) {
            if (__builtin_popcount(i) == 1) continue;
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) continue;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    int prv = i ^ (1 << j);
                    if (!(prv & (1 << k))) continue;
                    if (is_square.find(nums[j] + nums[k]) == is_square.end()) continue;
                    dp[i][j] += dp[prv][k];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[(1 << n) - 1][i];
        }
        for (auto e : cnt) {
            ans /= fc[e.second];
        }
        return ans;
    }
};