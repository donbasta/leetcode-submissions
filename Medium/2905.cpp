class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        pair<int, int> mn = make_pair(nums.back(), n - 1);
        pair<int, int> mx = make_pair(nums.back(), n - 1);
        for (int i = n - 1 - indexDifference; i >= 0; i--) {
            if (abs(mx.first - nums[i]) >= valueDifference) {
                return vector<int>{i, mx.second};
            }
            if (abs(mn.first - nums[i]) >= valueDifference) {
                return vector<int>{i, mn.second};
            }
            if (i + indexDifference - 1 >= 0) {
                if (nums[i + indexDifference - 1] < mn.first) {
                    mn = make_pair(nums[i + indexDifference - 1], i + indexDifference - 1);
                }
                if (nums[i + indexDifference - 1] > mx.first) {
                    mx = make_pair(nums[i + indexDifference - 1], i + indexDifference - 1);
                }
            }
        }
        return vector<int>{-1, -1};
    }
};