class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        for (auto e : nums) ret.push_back(e * e);
        sort(ret.begin(), ret.end());
        return ret;
    }
};