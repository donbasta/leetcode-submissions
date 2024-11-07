class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        set<int> se;
        se.insert(0);
        int pref = 0;
        int ans = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            // cout << pref << ' ' << *se.begin() << '\n';
            ans = max(ans, pref - *se.begin());
            se.insert(pref);
        }
        return ans;
    }
};