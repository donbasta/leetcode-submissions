class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref;
        pref.push_back(0);
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cur += (nums[i] & 1);
            int a = upper_bound(pref.begin(), pref.end(), cur - k) - pref.begin();
            int b = lower_bound(pref.begin(), pref.end(), cur - k) - pref.begin();
            ans += (a - b);
            pref.push_back(cur);
        }
        return ans;
    }
};