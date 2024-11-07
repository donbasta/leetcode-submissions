class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return false;
        int lmao = INT_MIN;
        set<int> se;
        se.insert(nums.back());
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < lmao) {
                return true;
            } else {
                auto x = se.lower_bound(nums[i]);
                if (x != se.begin()) {
                    lmao = max(lmao, *(--x));
                }
            }
            se.insert(nums[i]);
        }
        return false;
    }
};