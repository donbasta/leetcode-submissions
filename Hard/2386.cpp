class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        ll mx_sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                mx_sum += nums[i];
            } else {
                nums[i] = -nums[i];
            }
        }
        if (k == 1) return mx_sum;
        sort(nums.begin(), nums.end());
        priority_queue<pair<ll, int>> pq;
        pq.emplace(-nums[0], 0);
        for (int i = 0; i < k - 1; i++) {
            auto now = pq.top();
            pq.pop();
            ll sub = -now.first, idx = now.second;
            if (i == k - 2) {
                return mx_sum - sub;
            }
            if (idx + 1 < n) {
                pq.emplace(-(nums[idx + 1] + sub), idx + 1);
                pq.emplace(-(nums[idx + 1] + sub - nums[idx]), idx + 1);
            }
        }
        return -1;
    }
};