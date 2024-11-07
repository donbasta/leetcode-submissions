class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        for (int i = 0; i < n; i++) {
            pre[i] = (nums[i] + (i ? pre[i - 1] : 0));
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = (nums[i] + ((i + 1 < n) ? suf[i + 1] : 0));
        }
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = abs(pre[i] - suf[i]);
        }
        return ret;
    }
};