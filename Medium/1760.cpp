class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int ans;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int need = 0;
            for (auto c : nums) {
                need += ((c + mid - 1) / mid) - 1;
            }
            if (need <= maxOperations) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};