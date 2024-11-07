class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (auto e : nums) {
            if (e < mx && e > mn) ans++;
        }
        return ans;
    }
};