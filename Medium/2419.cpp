class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = *max_element(nums.begin(), nums.end());
        int tmp = 0;
        int ans = 0;
        for (auto e : nums) {
            if (e == val) tmp++;
            else {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        ans = max(ans, tmp);
        return ans;
    }
};