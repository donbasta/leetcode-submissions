class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) mp[i - nums[i]]++;
        long long ret = 1ll * n * (n - 1) / 2;
        for (auto e : mp) {
            ret -= (1ll * e.second * (e.second - 1)) / 2;
        }
        return ret;
    }
};