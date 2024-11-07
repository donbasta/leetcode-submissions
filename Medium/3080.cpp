class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        set<pair<int, int>> se;
        int n = nums.size();
        vector<long long> ret;
        long long tot = 0;
        for (int i = 0; i < n; i++) se.emplace(nums[i], i), tot += nums[i];
        for (auto Q : queries) {
            int idx = Q[0], k = Q[1];
            if (se.count(make_pair(nums[idx], idx))) {
                se.erase(make_pair(nums[idx], idx));
                tot -= nums[idx];
            }
            for (int j = 0; j < k; j++) {
                if (se.empty()) break;
                tot -= se.begin()->first;
                se.erase(se.begin());
            }
            ret.push_back(tot);
        }
        return ret;
    }
};