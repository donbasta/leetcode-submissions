class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            } 
            int pos = 0;
            for (int j = 0; j < 30; j++) {
                if (!((nums[i] >> j) & 1)) {
                    pos = j;
                    break;
                }
            }
            ans[i] = (nums[i] - (1 << (pos - 1)));
        }
        return ans;
    }
};