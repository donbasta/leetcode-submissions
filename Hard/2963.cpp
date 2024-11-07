class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> le, ri;
        for (int i = 0; i < n; i++) {
            if (!le.count(nums[i])) le[nums[i]] = i;
            ri[nums[i]] = i;
        }
        vector<pair<int, int>> ve;
        for (auto e : le) {
            ve.emplace_back(le[e.first], ri[e.first]);
        }
        sort(ve.begin(), ve.end());
        int L = ve[0].first, R = ve[0].second;
        int cmp = 1;
        for (int i = 1; i < (int)ve.size(); i++) {
            if (ve[i].first > R) {
                cmp++;
                L = ve[i].first;
                R = ve[i].second;
            } else {
                R = max(R, ve[i].second);
            }
        }
        int ans = 1;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < cmp - 1; i++) {
            ans = (1ll * ans * 2) % MOD;
        }
        return ans;
    }
};