class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x = 0, y = 0;
        for (auto n : nums) {
            x += n;
            while (n) {
                y += n % 10;
                n /= 10;
            }
        }
        return abs(x - y);
    }
};