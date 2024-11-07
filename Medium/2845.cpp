class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0]++;
        int tot = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            tot += (nums[i] % modulo == k);
            int need = (tot - k) % modulo;
            if (need < 0) need += modulo;
            ans += cnt[need];
            int now = tot % modulo;
            if (now < 0) now += modulo;
            cnt[now]++;
        }
        return ans;
    }
};