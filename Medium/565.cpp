class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int len = 0;
            int tmp = i;
            while (!vis[tmp]) {
                len++;
                vis[tmp] = true;
                tmp = nums[tmp];
            }
            ans = max(ans, len);
        }
        return ans;
    }
};