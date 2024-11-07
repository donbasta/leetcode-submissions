class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> se;
        se.insert(nums[0]);
        int n = nums.size();
        int j = 1;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            while (j < n) {
                if (*se.rbegin() - *se.begin() > limit) break;
                se.insert(nums[j]);
                j++;
                if (*se.rbegin() - *se.begin() <= limit) {
                    ans = max(ans, (int)se.size());
                } else {
                    break;
                }
            }
            se.erase(se.find(nums[i]));
        }
        return ans;
    }
};