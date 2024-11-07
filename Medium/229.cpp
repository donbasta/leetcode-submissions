class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        vector<int> ret;
        for (auto e : cnt) {
            if (e.second > n / 3) {
                ret.push_back(e.first);
            }
        }
        return ret;
    }
};