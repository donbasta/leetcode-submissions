class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n - 1; i++) {
            multiset<int> se;
            se.insert(nums[i]);
            se.insert(nums[i + 1]);
            int last = 0;
            if (abs(nums[i + 1] - nums[i]) > 1) {
                last++;
            }
            ret += last;
            for (int j = i + 2; j < n; j++) {
                auto x = se.upper_bound(nums[j]);
                if (x == se.begin()) {
                    if (*x - nums[j] > 1) last++;
                } else if (x == se.end()) {
                    if (nums[j] - *(--x) > 1) last++;
                } else {
                    auto y = x;
                    --y;
                    if (*x - *y > 1) last--;
                    if (*x - nums[j] > 1) last++;
                    if (nums[j] - *y > 1) last++;
                }
                se.insert(nums[j]);
                ret += last;
            }
        }
        return ret;
    }
};