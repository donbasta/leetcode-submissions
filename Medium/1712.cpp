class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
        int tot = pre[n - 1];
        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            // left until index i
            int left = pre[i];
            if (left * 3 > tot) break;
            // mid until index j: mid = pre[j] - pre[i] --> mid >= left
            // right = tot - left - mid >= mid --> mid <= (tot - left) / 2
            // pre[j] between [2 * pre[i], (tot + pre[i]) / 2];
            int a = lower_bound(pre.begin() + i + 1, pre.begin() + n - 1, pre[i] * 2) - pre.begin();
            int b = upper_bound(pre.begin() + i + 1, pre.begin() + n - 1, (tot + pre[i]) / 2) - pre.begin();
            if (b < a) continue;
            ans = (ans + b - a) % MOD;
        }
        return ans;
    }
};