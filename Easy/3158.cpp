class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int, int> cnt;
        for (auto e : nums) {
            cnt[e]++;
        }
        int ret = 0;
        for (auto e : cnt) {
            if (e.second == 2) ret ^= e.first;
        }
        return ret;
    }
};