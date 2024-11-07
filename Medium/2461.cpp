class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curSum = 0;
        set<pair<int, int>> se;
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; i++) {
            curSum += nums[i];
            if (cnt[nums[i]] == 0) {
                se.emplace(1, nums[i]);
            } else {
                se.erase(se.find(make_pair(cnt[nums[i]], nums[i])));
                se.emplace(cnt[nums[i]] + 1, nums[i]);
            }
            cnt[nums[i]]++;
        }
        long long ans = 0;
        if (se.rbegin()->first == 1) ans = max(ans, curSum);
        int n = nums.size();
        for (int i = k; i < n; i++) {
            curSum += nums[i];
            curSum -= nums[i - k];
            if (cnt[nums[i]] == 0) {
                se.emplace(1, nums[i]);
            } else {
                se.erase(se.find(make_pair(cnt[nums[i]], nums[i])));
                se.emplace(cnt[nums[i]] + 1, nums[i]);
            }
            cnt[nums[i]]++;
            se.erase(se.find(make_pair(cnt[nums[i - k]], nums[i - k])));
            cnt[nums[i - k]]--;
            if (cnt[nums[i - k]] > 0) {
                se.emplace(cnt[nums[i - k]], nums[i - k]);
            }
            if (se.rbegin()->first == 1) ans = max(ans, curSum);
        }
        return ans;
    }
};