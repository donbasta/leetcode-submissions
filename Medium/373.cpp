class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int INF = 2e9;
        long long lo = -INF, hi = INF;
        long long ans;
        while (lo <= hi) {
            long long mid = (1ll * lo + hi) >> 1;
            int i1 = 0, i2 = nums2.size() - 1;
            long long tmp = 0;
            while (i1 < nums1.size()) {
                while (i2 >= 0 && (1ll * nums1[i1] + nums2[i2] > mid)) {
                    i2--;
                }
                tmp += (i2 + 1);
                i1++;
            }
            if (tmp >= 1ll * k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        vector<vector<int>> ret;
        for (int i = 0; i < nums1.size(); i++) {
            int idx = 0;
            while (idx < nums2.size() && (1ll * nums1[i] + nums2[idx] <= ans)) {
                ret.push_back({nums1[i], nums2[idx]});
                idx++;
            }
        }
        sort(ret.begin(), ret.end(), [&](vector<int> a, vector<int> b) -> bool {
            return a[0] + a[1] < b[0] + b[1];
        });
        while (ret.size() > k) ret.pop_back();
        return ret;
    }
};