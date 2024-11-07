class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> lol(n);
        for (int i = 0; i < n; i++) {
            lol[i] = make_pair(nums[i], i);
        }
        sort(lol.begin(), lol.end());
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = lol[l].first + lol[r].first;
            if (sum == target) {
                return vector<int>{lol[l].second, lol[r].second};
            }
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            }
        }
        assert(false);
    }
};