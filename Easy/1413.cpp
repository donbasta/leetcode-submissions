class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0, cur = 0;
        for (auto e : nums) {
            cur += e;
            mn = min(mn, cur);
        }
        return max(1, 1 - mn);
    }
};