class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int tot = 0;
        for (auto e : nums) tot = (tot + e) % p;
        if (tot == 0) return 0;
        int n = nums.size();
        unordered_map<int, int> last;
        int tmp = 0;
        int ans = INT_MAX;
        last[0] = -1;
        for (int i = 0; i < n; i++) {
            tmp = (tmp + nums[i]) % p;
            int need = (tmp - tot) % p;
            if (need < 0) need += p;
            if (last.find(need) == last.end()) {
                last[tmp] = i;
                continue;
            }
            ans = min(ans, i - last[need]);
            last[tmp] = i;
        }
        if (ans == INT_MAX) return -1;
        if (ans == n) return -1;
        return ans;
    }
};