class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> cnt;
        int dis = 0;
        int n = nums.size();
        long long cur_tot = 0;
        for (int i = 0; i < k - 1; i++) {
            if (cnt.find(nums[i]) == cnt.end()) dis++;
            cnt[nums[i]]++;
            cur_tot += nums[i];
        }
        long long ans = 0;
        for (int i = k - 1; i < n; i++) {
            if (cnt.find(nums[i]) == cnt.end()) dis++;
            cnt[nums[i]]++;
            cur_tot += nums[i];
            if (dis >= m) {
                ans = max(ans, cur_tot);
            }
            cur_tot -= nums[i - k + 1];
            cnt[nums[i - k + 1]]--;
            if (cnt[nums[i - k + 1]] == 0) {
                dis--;
                cnt.erase(nums[i - k + 1]);
            }
        }
        return ans;
    }
};