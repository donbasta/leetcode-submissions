class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int a = *max_element(nums.begin(), nums.end());
        int b = *min_element(nums.begin(), nums.end());
        for (auto e : nums) {
            if (e != a && e != b) return e;
        }
        return -1;
    }
};