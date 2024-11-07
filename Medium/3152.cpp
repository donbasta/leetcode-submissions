class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i & 1) nums[i]++;
            nums[i] = nums[i] & 1;
        }
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = (i ? pre[i - 1] : 0) + nums[i];
        }
        vector<bool> ret;
        for (auto q : queries) {
            int l = q[0], r = q[1];
            int sum = pre[r] - (l ? pre[l - 1] : 0);
            ret.push_back(((sum == 0) || (sum == r - l + 1)));
        }
        return ret;
    }
};