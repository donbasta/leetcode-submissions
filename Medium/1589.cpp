class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int lmao[n + 1];
        memset(lmao, 0, sizeof(lmao));
        for (auto r : requests) {
            lmao[r[0]]++;
            lmao[r[1] + 1]--;
        }
        for (int i = 1; i < n; i++) {
            lmao[i] += lmao[i - 1];
        }
        sort(lmao, lmao + n, greater<int>());
        sort(nums.rbegin(), nums.rend());
        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (1ll * ans + 1ll * nums[i] * lmao[i]) % MOD;
        }
        return ans;
    }
};