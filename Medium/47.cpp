class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> se;
        sort(nums.begin(), nums.end());
        do {
            se.insert(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return vector<vector<int>>(se.begin(), se.end());
    }
};