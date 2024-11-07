class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int dif[n + 1];
        for (int i = 0; i < n; i++) {
            dif[i] = abs(nums1[i] - nums2[i]);
        }
        dif[n] = 0;
        sort(dif, dif + n + 1, greater<int>());
        int val = dif[0];
        int k = k1 + k2;
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            if (dif[i] != val) {
                int sel = val - dif[i];
                if (1ll * sel * i < 1ll * k) {
                    k -= sel * i;
                } else {
                    int a = k / i;
                    int b = k % i;
                    for (int j = 0; j < i; j++) {
                        if (j < b) ans += 1ll * (val - a - 1) * (val - a - 1);
                        else ans += 1ll * (val - a) * (val - a);
                    }
                    for (int j = i; j < n; j++) {
                        ans += 1ll * dif[j] * dif[j];
                    }
                    return ans;
                }
                val = dif[i];
            }
        }
        if (1ll * val * n < 1ll * k) {
            ans = 0ll;
        } else {
            int a = k / n, b = k % n;
            for (int i = 0; i < n; i++) {
                if (i < b) ans += 1ll * (val - a - 1) * (val - a - 1);
                else ans += 1ll * (val - a) * (val - a);
            }
        }
        return ans;
    }
};