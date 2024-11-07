class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> A(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) A[i] = 1;
            if (nums[i] == nums[i + 1]) A[i] = 0;
            if (nums[i] > nums[i + 1]) A[i] = -1;
        }
        int ans = 0;
        for (int i = 0; i + m - 1 < n - 1; i++) {
            bool ok = true;
            for (int j = i; j < i + m; j++) {
                if (A[j] != pattern[j - i]) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};