class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> cnt(1001);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (auto e : nums[i]) cnt[e]++;
        }
        vector<int> ret;
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] == n) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};