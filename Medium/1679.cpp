class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        for (auto n : nums) {
            cnt[n]++;
        }
        int ans = 0;
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        // for (auto e : nums) cout << e << ' ' << cnt[e] << ' '; 
        for (auto n : nums) {
            if (n * 2 == k) {
                ans += (cnt[n] / 2);
            } else if (n * 2 > k) { 
                break;
            } else {
                ans += min(cnt[n], cnt[k - n]);
            }
        }
        return ans;
    }
};