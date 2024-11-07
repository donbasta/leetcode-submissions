class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6;
        int ret = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            long long sum = 0;
            for (auto c : nums) {
                sum += (c + mid - 1) / mid;
            }
            if (sum <= threshold) {
                ret = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ret;
    }
};