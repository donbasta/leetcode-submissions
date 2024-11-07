class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int M = 100;
        vector<int> cnt(M + 1);
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for (auto c : arr) cnt[c]++;
        for (int i = 0; i <= M; i++) {
            if (i > target) break;
            for (int j = i + 1; j <= M; j++) {
                if (i + j > target) break;
                int k = target - i - j;
                if (k <= j) break;
                if (k > M) continue;
                ans += 1ll * cnt[i] * cnt[j] * cnt[k];
                ans %= MOD;
            }
        }
        for (int i = 0; i <= M; i++) {
            if (2 * i > target) break;
            if (3 * i == target) continue;
            if (target - 2 * i > M) continue;
            ans += 1ll * (cnt[i]) * (cnt[i] - 1) / 2 * cnt[target - 2 * i];
            ans %= MOD;
        }
        if (target % 3 == 0) {
            int x = target / 3;
            ans += 1ll * cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) / 6;
            ans %= MOD;
        }
        return ans;
    }
};