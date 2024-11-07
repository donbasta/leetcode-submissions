class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> q;
        const int INF = 2e9;
        vector<int> ans(n, -INF);
        for (int i = 0; i < n; i++) {
            while (!q.empty() && (q.back().first < nums[i])) {
                ans[q.back().second] = nums[i];
                q.pop_back();
            }
            q.emplace_back(nums[i], i);
        }
        for (int i = 0; i < n; i++) {
            while (!q.empty() && (q.back().first < nums[i])) {
                ans[q.back().second] = nums[i];
                q.pop_back();
            }
            if (ans[i] == -INF) {
                q.emplace_back(nums[i], i);
            }
        }
        for (auto& e : ans) {
            if (e == -INF) e = -1;
        }
        return ans;
    }
};