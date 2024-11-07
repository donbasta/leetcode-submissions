class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ve(n);
        set<int> tmp;
        for (int i = n - 1; i >= 0; i--) {
            ve[i] = tmp.size();
            tmp.insert(nums[i]);
        }
        tmp.clear();
        for (int i = 0; i < n; i++) {
            tmp.insert(nums[i]);
            ve[i] = (int)tmp.size() - ve[i];
        }
        return ve;
    }
};