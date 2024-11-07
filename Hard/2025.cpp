class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        ll tot = accumulate(nums.begin(), nums.end(), 0ll);
        vector<ll> pref(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pref[i] = (i ? pref[i - 1] : 0) + nums[i];
            if (i < n - 1 && pref[i] * 2 == tot) ans++;
        }

        vector<int> cnt(n);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            tot += k - nums[i];
            if (tot % 2 == 0) {
                cnt[i] += freq[tot / 2];
            }
            freq[pref[i]]++;
            tot -= k - nums[i];
        }
        freq.clear();
        for (int i = n - 2; i >= 0; i--) {
            tot += k - nums[i];
            freq[pref[i]]++;
            if (tot % 2 == 0) {
                cnt[i] += freq[tot / 2 - (k - nums[i])];
            }
            tot -= k - nums[i];
        }
        for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
        return ans;
    }
};