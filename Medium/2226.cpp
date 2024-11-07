class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1, hi = *max_element(candies.begin(), candies.end());
        int ret = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            long long avail = 0;
            for (auto c : candies) {
                avail += c / mid;
            }
            if (avail >= k) {
                ret = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ret;
    }
};