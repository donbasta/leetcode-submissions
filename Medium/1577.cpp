class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> cnt1, cnt2;
        for (auto e : nums1) cnt1[e]++;
        for (auto e : nums2) cnt2[e]++;
        int ans = 0;
        for (auto e : nums1) {
            for (int i = 1; i <= e; i++) {
                if ((1ll * e * e) % i != 0) continue;
                long long j = 1ll * e * e / i;
                if (i != j) {
                    ans += cnt2[i] * cnt2[j];
                } else {
                    ans += cnt2[i] * (cnt2[i] - 1) / 2;
                }
            }
        }
        for (auto e : nums2) {
            for (int i = 1; i <= e; i++) {
                if ((1ll * e * e) % i != 0) continue;
                long long j = 1ll * e * e / i;
                if (i != j) {
                    ans += cnt1[i] * cnt1[j];
                } else {
                    ans += cnt1[i] * (cnt1[i] - 1) / 2;
                }
            }
        }
        return ans;
    }
};