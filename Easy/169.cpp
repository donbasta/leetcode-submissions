class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (auto e : nums) ump[e]++;
        int mx = 0, ans = -1;
        for (auto [x, y] : ump) {
            if (y > mx) {
                mx = y, ans = x;
            }
        }
        return ans;
    }
};