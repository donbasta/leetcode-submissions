class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            cnt[nums[i] + nums[i + 1]]++;
            if (cnt[nums[i] + nums[i + 1]] >= 2) return true;
        }
        return false;
    }
};