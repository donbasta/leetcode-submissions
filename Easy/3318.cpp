class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = 0; i <= n - k; i++) {
            vector<int> cnt(51);
            for (int j = i; j <= i + k - 1; j++) {
                cnt[nums[j]]++;
            }
            vector<pair<int, int>> ve;
            for (int j = 1; j <= 50; j++) {
                ve.emplace_back(cnt[j], j);
            }
            sort(ve.begin(), ve.end());
            reverse(ve.begin(), ve.end());
            for (int j = 0; j < x; j++) {
                ans[i] += ve[j].first * ve[j].second;
            }
        }
        return ans;
    }
};