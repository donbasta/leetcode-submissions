class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        vector<int> le(n, -1), tmp;
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && nums[tmp.back()] < nums[i]) {
                le[tmp.back()] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i);
        }
        
        using ll = long long;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int u = upper_bound(pos[nums[i]].begin(), pos[nums[i]].end(), le[i]) - pos[nums[i]].begin();
            int v = upper_bound(pos[nums[i]].begin(), pos[nums[i]].end(), i) - pos[nums[i]].begin();
            ans += v - u;
        }
        return ans;
    }
};