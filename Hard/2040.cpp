class Solution {
public:
    long long floor(long long a, long long b) {
        assert (b != 0);
        if (a == 0) return 0;
        if ((a > 0) && (b > 0)) return a / b;
        if ((a < 0) && (b < 0)) return abs(a) / abs(b);

        long long aa = abs(a), bb = abs(b);
        long long r = aa / bb;
        return -(r + (aa % bb != 0));
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, r = 1e10;
        int s1 = nums1.size(), s2 = nums2.size();
        long long ans;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long tot = 0;
            for (int i = 0; i < s1; i++) {
                if (nums1[i] > 0) {
                    long long r = floor(mid, nums1[i]);
                    tot += upper_bound(nums2.begin(), nums2.end(), r) - nums2.begin();
                } else if (nums1[i] == 0) {
                    tot += 1ll * (0 <= mid) * s2;
                } else {
                    long long r = floor(mid, nums1[i]);
                    if (abs(mid) % abs(nums1[i]) != 0) r++;
                    tot += (s2 - (lower_bound(nums2.begin(), nums2.end(), r) - nums2.begin()));
                }
            }

            if (tot >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};