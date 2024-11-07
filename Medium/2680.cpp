class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        vector<int> P(n), S(n);
        P[0] = nums[0];
        for (int i = 1; i < n; i++) P[i] = (P[i - 1] | nums[i]);
        S[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) S[i] = (S[i + 1] | nums[i]);

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int L = (i ? P[i - 1] : 0);
            int R = (i < n - 1 ? S[i + 1] : 0);
            ans = max(ans, (((1ll * nums[i]) << k)) | L | R);
        }
        return ans;
    }
};