class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int st = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                st = i; break;
            }
        }
        assert(st != -1);
        unordered_map<int, int> cnt;
        int cur = 0;
        for (int i = st - 1; i >= 0; i--) {
            cnt[cur]++;
            if (nums[i] < k) cur--;
            else if (nums[i] > k) cur++;
        }
        cnt[cur]++;
        cur = 0; 
        int ans = 0;
        for (int i = st + 1; i < n; i++) {
            ans += cnt[-cur];
            ans += cnt[1 - cur];
            if (nums[i] < k) cur--;
            else if (nums[i] > k) cur++;
        }
        ans += cnt[-cur];
        ans += cnt[1 - cur];
        return ans;
    }
};