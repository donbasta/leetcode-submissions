class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int pivot = nums[(n - 1) / 2];
        int ans = 0;
        for (auto e : nums) {
            ans += abs(e - pivot);
        }
        return ans;
    }
};