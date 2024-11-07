class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            int sel = 1;
            while (j < n && nums[j] - nums[j - 1] == sel) {
                j++;
                sel = -sel;
            }
            int len = j - i;
            if (len > 1) ans = max(ans, len);
        }
        return ans;
    }
};