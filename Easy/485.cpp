class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int ans = 0;
        for (auto e : nums) {
            if (e == 0) cur = 0;
            else {
                cur++;
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};