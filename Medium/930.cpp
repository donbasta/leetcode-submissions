class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> cnt;
        cnt[0]++;
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            ans += cnt[tmp - goal];
            cnt[tmp]++;
        }
        return ans;
    }
};