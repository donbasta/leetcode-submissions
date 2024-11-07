class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), cnt(n);
        for (auto e : nums) cnt[e]++;
        pre[0] = cnt[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        int ans = 0;
        if (cnt[0] == 0) ans++; //choosing nobody
        for (int i = 1; i <= n; i++) {
            if (i < n && cnt[i] > 0) continue;
            if (pre[i - 1] != i) continue;
            ans++;
        }
        return ans;
    }
};