class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int B = 30;
        const int MOD = 1e9 + 7;
        vector<int> cnt(B);
        for (auto c : nums) {
            for (int i = 0; i < B; i++) {
                if ((c >> i) & 1) cnt[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            int tmp = 0;
            for (int j = B - 1; j >= 0; j--) {
                if (cnt[j] > 0) {
                    tmp += (1 << j);
                    cnt[j]--;
                }
            }
            ans = (1ll * tmp * tmp + ans) % MOD;
        }
        return ans;
    }
};