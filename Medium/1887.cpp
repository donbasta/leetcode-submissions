class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += i * cnt[nums[i]];
        }
        return ans;
    }
};