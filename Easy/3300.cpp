class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        auto sum_digit = [&](int x) -> int {
            int ret = 0;
            while (x) {
                ret += x % 10;
                x /= 10;
            }
            return ret;
        };
        for (auto e : nums) {
            mn = min(mn, sum_digit(e));
        }
        return mn;
    }
};