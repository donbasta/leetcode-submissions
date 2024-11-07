class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> freq;
        for (auto n : nums) freq[n]++;
        int ans = 0;
        for (auto mp : freq) if (mp.second == 1) ans += mp.first;
        return ans;
    }
};