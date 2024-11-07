class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos[n + 1];
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() <= 1) continue;
            int tot = pos[i][1] - pos[i][0] - 1;
            int sz = pos[i].size();
            int ve[sz];
            ve[0] = 0, ve[1] = tot;
            for (int j = 2; j < sz; j++) {
                tot += pos[i][j] - pos[i][j - 1] - 1;
                ve[j] = tot;
            }
            for (int j = 1; j < sz; j++) {
                int idx = upper_bound(ve, ve + sz, ve[j - 1] + k) - ve - 1;
                ans = max(ans, idx - j + 2);
            }
        }
        return ans;
    }
};