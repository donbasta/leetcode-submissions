class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto e : positions) {
            int sz = e.second.size();
            int itv = 0;
            for (int i = 0; i < sz; i++) {
                int nx;
                if (i < sz - 1) nx = e.second[i + 1];
                else nx = e.second[0] + n;
                itv = max(itv, nx - e.second[i] - 1);
            }
            ans = min(ans, (itv + 1) / 2);
        }
        return ans;
    }
};