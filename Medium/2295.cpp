class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; i++) pos[nums[i]] = i;
        for (auto q : operations) {
            nums[pos[q[0]]] = q[1];
            pos[q[1]] = pos[q[0]];
            pos.erase(q[0]);
        }
        return nums;
    }
};