class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int len = 1;
        int n = nums.size();
        bool is_increasing = true;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (is_increasing) {
                if (nums[i] > nums[i - 1]) {
                    len++;
                } else if (nums[i] < nums[i - 1]) {
                    if (len > 1) {
                        len++;
                        is_increasing = false;
                    } else {
                        len = 1;
                    }
                } else if (nums[i] == nums[i - 1]) {
                    len = 1;
                }
            } else {
                if (nums[i] < nums[i - 1]) {
                    len++;
                } else if (nums[i] > nums[i - 1]) {
                    ans = max(ans, len);
                    len = 2;
                    is_increasing = true;
                } else if (nums[i] == nums[i - 1]) {
                    ans = max(ans, len);
                    len = 1;
                    is_increasing = true;
                }
            }
        }
        if (!is_increasing && (len > 1)) ans = max(ans, len);
        return ans;
    }
};