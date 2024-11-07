class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        const int INF = 1e9;
        int ans = INF;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int atau = 0;
                for (int k = i; k <= j; k++) atau = (atau | nums[k]);
                if (atau >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        if (ans == INF) return -1;
        return ans;
    }
};