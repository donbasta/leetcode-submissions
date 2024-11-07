class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;
        vector<bool> pre(n), suf(n);
        pre[0] = true;
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] && (nums[i - 1] <= nums[i]));
        }
        suf.back() = true;
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = (suf[i + 1] && (nums[i] <= nums[i + 1]));
        }
        for (int i = 1; i < n - 1; i++) {
            if (pre[i - 1] && suf[i + 1] && (nums[i - 1] <= nums[i + 1])) return true;
        }
        if (suf[1]) return true;
        if (pre[n - 2]) return true;
        return false;
    }
};