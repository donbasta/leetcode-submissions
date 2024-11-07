class Solution {
public:
    int maxSum(vector<int>& nums) {
        const function<char(int)> maxDigit = [&](int x) -> char {
            string s = to_string(x);
            char c = '\0';
            for (auto e : s) c = max(c, e);
            return c;
        };
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (maxDigit(nums[i]) != maxDigit(nums[j])) continue;
                ans = max(ans, nums[i] + nums[j]);
            }
        }
        return ans;
    }
};