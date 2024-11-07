class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> pre(4e5);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int A = nums[i] - k + 1e5;
            int B = nums[i] + k + 1e5;
            pre[A]++, pre[B + 1]--;
        }
        for (int i = 1; i < 4e5; i++) {
            pre[i] += pre[i - 1];
        }
        int mx = 0;
        for (int i = 0; i < 4e5; i++) {
            mx = max(mx, pre[i]);
        }
        return mx;
    }
};