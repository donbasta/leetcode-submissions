class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        for (auto e : cnt) if (e.second & 1) return false;
        return true;
    }
};