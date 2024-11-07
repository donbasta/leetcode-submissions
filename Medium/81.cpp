class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto e : nums) if (e == target) return true;
        return false;
    }
};