class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> se;
        for (auto e : nums) {
            for (int i = e[0]; i <= e[1]; i++) {
                se.insert(i);
            }
        }
        return se.size();
    }
};