class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right;
        int cnt = 0;
        for (auto e : nums) {
            if (e < pivot) left.push_back(e);
            else if (e > pivot) right.push_back(e);
            else cnt++;
        }
        for (int i = 0; i < cnt; i++) {
            left.push_back(pivot);
        }
        for (auto e : right) {
            left.push_back(e);
        }
        return left;
    }
};