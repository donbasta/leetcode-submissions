class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int tmp = 0;
            int sub = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (tmp + nums[i] > mid) {
                    sub++;
                    tmp = nums[i];
                } else {
                    tmp += nums[i];
                }
            }
            sub++;
            if (sub <= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        assert (ans != -1);
        return ans;
    }
};