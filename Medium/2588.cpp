class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0]++;
        int tmp = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            tmp ^= (nums[i]);
            ans += cnt[tmp];
            cnt[tmp]++;
        }
        return ans;
    }
};