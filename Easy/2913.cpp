class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            set<int> se;
            for (int j = i; j < n; j++) {
                se.insert(nums[j]);
                int sz = se.size();
                ans += sz * sz;
            }
        }
        return ans;
    }
};