class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int cap = n / k;

        const int INF = 2e9;
        int cost[1 << n], dp[1 << n];
        for (int i = 0; i < (1 << n); i++) cost[i] = dp[i] = INF;
        vector<int> gr;
        for (int i = 0; i < (1 << n); i++) {
            int sz = __builtin_popcount(i);
            if (sz != cap) continue;
            bool cnt[n + 1];
            memset(cnt, false, sizeof(cnt));
            bool ok = true;
            int mx = -1, mn = n + 1;
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                if (cnt[nums[j]]) { ok = false; break; }
                cnt[nums[j]] = true;
                mx = max(mx, nums[j]), mn = min(mn, nums[j]);
            }
            if (!ok) continue;
            dp[i] = mx - mn;
            cost[i] = mx - mn;
            gr.push_back(i);
        }

        for (int i = 1; i < (1 << n); i++) {
            int sz = __builtin_popcount(i);
            if (sz == cap) continue;
            if (sz % cap != 0) continue;
            for (auto c : gr) {
                if ((c | i) != i) continue;
                dp[i] = min(dp[i], dp[i ^ c] + cost[c]);
            }
        }

        if (dp[(1 << n) - 1] == INF) return -1;
        return dp[(1 << n) - 1];
    }
};