class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int suf = 0;
        unordered_map<int, int> ump;
        int n = nums.size();
        int ans = INT_MAX;
        ump[suf] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (ump.find(x - tot) != ump.end()) {
                ans = min(ans, i + 1 + ump[x - tot]);
            }
            tot -= nums[i];
            suf += nums[i];
            ump[suf] = n - i;
        }
        if (ump.find(x) != ump.end()) {
            ans = min(ans, ump[x]);
        }
        if (ans == INT_MAX) return -1; 
        return ans;
    }
};