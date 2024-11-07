class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int pre[n + 1];
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) pre[i + 1] = pre[i] + 1;
            else pre[i + 1] = pre[i] - 1;
        }
        int M = 1e5;
        int ri[2 * M + 5];
        memset(ri, -1, sizeof(ri));
        ri[pre[n] + M] = n;
        ri[pre[n - 1] + M] = n - 1;
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (ri[pre[i] + M] != -1) ans = max(ans, ri[pre[i] + M] - i);
            else ri[pre[i] + M] = i;
        }
        return ans;
    }
};