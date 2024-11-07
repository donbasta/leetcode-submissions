class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ve(n);
        for (int i = 0; i < n; i++) {
            ve[i] = nums[nums[i]];
        }
        return ve;
    }
};