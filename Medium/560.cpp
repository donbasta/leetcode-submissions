class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cntPref;
        int tot = 0;
        cntPref[0]++;
        int ans = 0;
        for (auto n : nums) {
            tot += n;
            ans += cntPref[tot - k];
            cntPref[tot]++;
        }
        return ans;
    }
};