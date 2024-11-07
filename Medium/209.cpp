class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r = 0;
        int sum = nums[0];
        const int INF = 2e9;
        int ans = INF;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while ((r < n - 1) && (sum < target)) {
                r++; sum += nums[r];
            }
            if (sum >= target) {
                ans = min(ans, r - i + 1);
            }
            sum -= nums[i];
        }
        if (ans == INF) ans = 0;
        return ans;
    }
};