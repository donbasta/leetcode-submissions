class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<int> se;
        for (int i = 0; i < n / 2; i++) {
            se.insert(nums[i] + nums[n - 1 - i]);
        }
        return se.size();
    }
};