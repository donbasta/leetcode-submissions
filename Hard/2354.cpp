class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bc;
        unordered_map<int, bool> ada;
        for (int i = 0; i < n; i++) {
            if (ada[nums[i]]) continue;
            bc.push_back(__builtin_popcount(nums[i]));
            ada[nums[i]] = true;
        }
        n = bc.size();
        int r = n - 1;
        long long ans = 0;
        sort(bc.begin(), bc.end());
        for (int i = 0; i < n; i++) {
            while (r >= 0 && bc[r] + bc[i] >= k) {
                r--;
            }
            ans += (n - 1 - r);
        }
        return ans;
    }
};