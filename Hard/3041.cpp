class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int, int> ump;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = 1, b = 1;
            if (ump.count(nums[i])) {
                b = max(b, ump[nums[i]] + 1);
            }
            if (ump.count(nums[i] - 1)) {
                a = max(a, ump[nums[i] - 1] + 1);
            }
            ump[nums[i]] = a, ump[nums[i] + 1] = b;
        }
        int ans = 1;
        for (auto e : ump) {
            ans = max(ans, e.second);
        }
        return ans;
    }
};