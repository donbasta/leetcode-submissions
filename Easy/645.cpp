class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        vector<int> ret(2);
        for (auto e : nums) cnt[e]++;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 2) ret[0] = i;
            if (cnt[i] == 0) ret[1] = i;
        }
        return ret;
    }
};