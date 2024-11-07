class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int M = 1e4;
        vector<int> cnt(M + 1);
        for (auto e : nums) {
            if (cnt[e] > 0) return e;
            cnt[e]++;
        }
        return -1;
    }
};