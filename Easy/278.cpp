// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        long long ret = -1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (isBadVersion(mid)) {
                ret = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }
};