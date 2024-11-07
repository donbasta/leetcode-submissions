class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            vector<int> cnt1(2), cnt2(2);
            for (auto e : nums1) cnt1[(e >> i) & 1] ^= 1;
            for (auto e : nums2) cnt2[(e >> i) & 1] ^= 1;
            int odd = cnt1[0] * cnt2[1] + cnt1[1] * cnt2[0];
            if (odd & 1) {
                ans += (1 << i);
            }
        }
        return ans;
    }
};