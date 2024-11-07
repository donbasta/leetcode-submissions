class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> se;
        int n = nums.size();
        using ll = long long;
        set<ll> ada;
        for (auto e : nums) ada.insert(e);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    ll need = 1ll * target - nums[i] - nums[j] - nums[k];
                    if (need < nums[k + 1]) {
                        break;
                    }
                    if (!ada.count(need)) continue;
                    se.insert(vector<int>{nums[i], nums[j], nums[k], (int)need});
                }
            }
        }
        return vector<vector<int>>(se.begin(), se.end());
    }
};