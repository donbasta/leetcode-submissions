class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cur = 0;
        vector<int> pref;
        pref.push_back(0);
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i] == 0;
            int a = lower_bound(pref.begin(), pref.end(), cur - k) - pref.begin();
            ans = max(ans, i + 1 - a);
            pref.push_back(cur);
        }
        return ans;
    }
};