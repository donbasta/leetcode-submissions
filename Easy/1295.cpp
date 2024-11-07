class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto n : nums) {
            ans += to_string(n).length() % 2 == 0;
        }
        return ans;
    }
};