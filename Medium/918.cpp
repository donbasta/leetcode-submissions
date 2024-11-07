class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        set<pair<int, int>> se;
        int n = nums.size();
        vector<int> pref(2 * n + 5);
        pref[0] = 0;
        se.emplace(pref[0], 0);
        int cur = 0;
        const int INF = 2e9;
        int ans = -INF;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            ans = max(ans, cur - se.begin()->first);
            pref[i + 1] = cur;
            se.emplace(pref[i + 1], i + 1);
        }
        for (int i = n; i < 2 * n; i++) {
            se.erase(se.find(make_pair(pref[i - n], i - n)));
            cur += nums[i - n];
            ans = max(ans, cur - se.begin()->first);
            se.emplace(cur, i + 1);
        }
        return ans;
    }
};