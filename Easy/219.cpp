class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> prv;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (prv.find(nums[i]) != prv.end()) {
                if (i - prv[nums[i]] <= k) return true;
            }
            prv[nums[i]] = i;
        }
        return false;
    }
};