class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int now = nums[0], n = nums.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            int tmp = now + nums[i];
            if (tmp == 0) ans++;
            now = tmp;
        }
        return ans;
    }
};