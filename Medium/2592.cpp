class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= nums[i]) j++;
            if (j >= n) break;
            ans++;
            j++;
        }
        return ans;
    }
};