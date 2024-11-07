class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];
        vector<long long> ret;
        for (auto q : queries) {
            int a = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long tmp = 1ll * a * q - (a ? pref[a - 1] : 0);
            tmp += (pref[n - 1] - (a ? pref[a - 1] : 0) - 1ll * (n - a) * q);
            ret.push_back(tmp);
        }
        return ret;
    }
};