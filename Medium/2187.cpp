class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = 1e18;
        long long ans = -1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long tmp = 0;
            for (auto t : time) {
                tmp += mid / t;
                if (tmp >= (long long)totalTrips) {
                    break;
                }
            }
            if (tmp >= (long long)totalTrips) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};