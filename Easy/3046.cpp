class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for (auto e : nums) ump[e]++;
        for (auto e : ump) {
            if (e.second > 2) return false;
        }
        return true;
    }
};