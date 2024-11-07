class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) nums[sz++] = i;
        }
        for (int i = 0; i < sz; i++) {
            nums[i] -= i;
        }
        int ki = 0, ka = 0;
        for (int i = 0; i < k / 2; i++) ki += nums[i];
        for (int i = k - 1; i >= k - (k / 2); i--) ka += nums[i];
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < sz; i++) {
            ans = min(ans, ka - ki);
            if (i + k < sz) {
                ki -= nums[i];
                ki += nums[i + k / 2];
                ka -= nums[i + k - (k / 2)];
                ka += nums[i + k];
            }
        }
        return ans;
    }
};