class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int k1 = 0, k2 = 0;
        long long s1 = 0, s2 = 0;
        for (auto e : nums1) {
            if (e == 0) {
                k1++;
            } else {
                s1 += e;
            }
        }
        for (auto e : nums2) {
            if (e == 0) {
                k2++;
            } else {
                s2 += e;
            }
        }
        // cout << s1 << ' ' << k1 << ' ' << s2 << ' ' << k2 << '\n';
        if (s1 == s2) {
            if ((k1 == 0 && k2 > 0) || (k1 > 0 && k2 == 0)) {
                return -1;
            }
            return s1 + max(k1, k2);
        }
        if (s1 > s2) {
            if (k2 == 0) return -1;
            if (k1 == 0 && s2 + k2 > s1) return -1;
            return max(s1 + k1, s2 + k2);
        }
        if (k1 == 0) return -1;
        if (k2 == 0 && s1 + k1 > s2) return -1;
        return max(s1 + k1, s2 + k2);
    }
};