class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1e9;
        vector<int> dl(n, INF), dr(n, INF);
        vector<int> kiri(n, 1), kanan(n, 1);
        dl[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int k = lower_bound(dl.begin(), dl.end(), nums[i]) - dl.begin();
            assert (k < n);
            dl[k] = nums[i];
            kiri[i] = k + 1;
        }
        dr[0] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int k = lower_bound(dr.begin(), dr.end(), nums[i]) - dr.begin();
            assert (k < n);
            dr[k] = nums[i];
            kanan[i] = k + 1;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (kiri[i] == 1 || kanan[i] == 1) continue;
            ans = max(ans, kiri[i] + kanan[i] - 1);
        }
        return n - ans;
    }
};