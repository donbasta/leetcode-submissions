class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = 1e6;
        int ans;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int tmp = 0;
            for (int i = 1; i < nums.size(); i++) {
                int t = lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid) - nums.begin();
                tmp += (i - t);
            }
            if (tmp >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};