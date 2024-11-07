class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto f = [&](int x) -> int {
            int ret = 0;
            string s = to_string(x);
            for (auto c : s) {
                ret = (ret * 10 + (mapping[c - '0']));
            }
            return ret;
        };
        stable_sort(nums.begin(), nums.end(), [&](int x, int y) -> bool {
            int a = f(x), b = f(y);
            // if (a == b) {
            //     return false;
            // }
            return a < b;
        });
        return nums;
    }
};