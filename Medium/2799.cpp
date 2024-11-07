class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> se;
        for (auto e : nums) se.insert(e);
        int tot = se.size();
        int n = nums.size();
        int ans = 0;
        int ptr = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            while (ptr < n && cnt.size() < tot) {
                cnt[nums[ptr]]++;
                ptr++;
            }
            if (cnt.size() == tot) ans += (n - ptr + 1);
            cnt[nums[i]]--;
            if (cnt[nums[i]] == 0) {
                cnt.erase(nums[i]);
            } 
        }
        return ans;
    }
};