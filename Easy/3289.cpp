class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n - 2);
        vector<int> ret;
        for (auto e : nums) {
            if (cnt[e] > 0) ret.push_back(e);
            cnt[e]++;
        }
        return ret;
    }
};