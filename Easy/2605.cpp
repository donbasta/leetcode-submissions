class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> c1(10), c2(10);
        for (auto e : nums1) c1[e] = true;
        for (auto e : nums2) c2[e] = true;
        int m1 = 10, m2 = 10;
        for (int i = 1; i <= 9; i++) {
            if (c1[i] && c2[i]) return i;
            if (c1[i]) m1 = min(m1, i);
            if (c2[i]) m2 = min(m2, i);
        }
        if (m1 > m2) swap(m1, m2);
        return 10 * m1 + m2;
    }
};