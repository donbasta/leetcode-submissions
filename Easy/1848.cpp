class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mn = INT_MAX;
        int n = nums.size();
        for (int i = start; i < n; i++) {
            if (nums[i] == target) mn = min(mn, i - start);
        }
        for (int i = start; i >= 0; i--) {
            if (nums[i] == target) mn = min(mn, start - i);
        }
        return mn;
    }
};