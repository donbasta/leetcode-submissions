class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using ll = long long;
        const ll N = 1e6;
        int c1[N + 1], c2[N + 1];
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));

        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++) {
            c1[nums1[i]]++;
        }
        for (int i = 0; i < m; i++) {
            c2[nums2[i]]++;
        }
        ll ret = 0;
        for (ll i = 1; i <= N; i++) {
            if (c2[i] == 0) continue;
            for (ll j = i * k; j <= N; j += i * k) {
                ret += 1ll * c2[i] * c1[j];
            }
        }
        return ret;
    }
};