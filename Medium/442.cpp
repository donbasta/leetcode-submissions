class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n);
        for (auto e : nums) {
            cnt[e - 1]++;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 2) ret.push_back(i + 1);
        }
        return ret;
    }
};