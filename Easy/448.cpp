class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            while (cur != -1) {
                int tmp = nums[cur - 1];
                nums[cur - 1] = -1;
                cur = tmp;
            }
        }
        vector<int> ve;
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) ve.push_back(i + 1); 
        }
        return ve;
    }
};