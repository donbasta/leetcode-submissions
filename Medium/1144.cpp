class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int tmp = 0;
            for (int j = i; j < n; j+= 2) {
                int lmao = INT_MAX;
                if (j > 0) lmao = min(lmao, nums[j - 1]);
                if (j < n - 1) lmao = min(lmao, nums[j + 1]);
                if (nums[j] >= lmao) {
                    tmp += nums[j] - lmao + 1;
                }
            }
            ans = min(ans, tmp);
        }
        return ans;
    }
};