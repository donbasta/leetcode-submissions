class Solution {
public:
    int minMoves(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (auto e : nums) ans += e - a;
        return ans;
    }
};