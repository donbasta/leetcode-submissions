class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a1 = 0, a2 = 1;
        bool ok1 = true, ok2 = true;
        for (int i = 0; i < n - 1; i++) {
            int x = nums1[i], y = nums2[i];
            if (x > nums1.back() || y > nums2.back()) {
                swap(x, y);
                a1++;
            }
            if (x > nums1.back() || y > nums2.back()) {
                ok1 = false;
                break;
            }
        }
        swap(nums1.back(), nums2.back());
        for (int i = 0; i < n - 1; i++) {
            int x = nums1[i], y = nums2[i];
            if (x > nums1.back() || y > nums2.back()) {
                swap(x, y);
                a2++;
            }
            if (x > nums1.back() || y > nums2.back()) {
                ok2 = false;
                break;
            }
        }
        int ret = INT_MAX;
        if (ok1) ret = min(ret, a1);
        if (ok2) ret = min(ret, a2);
        if (ret == INT_MAX) return -1;
        return ret;
    }
};