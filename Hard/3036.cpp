class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> A(n - 1 + 1 + m);
        for (int i = 0; i < m; i++) A[i] = pattern[i];
        A[m] = 69;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) A[i + m + 1] = 1;
            if (nums[i] == nums[i + 1]) A[i + m + 1] = 0;
            if (nums[i] > nums[i + 1]) A[i + m + 1] = -1;
        }
        vector<int> pi(n + m);
        for (int i = 1; i < n + m; i++) {
            int j = pi[i - 1];
            while (j > 0 && A[i] != A[j])
                j = pi[j - 1];
            if (A[i] == A[j])
                j++;
            pi[i] = j;
        }
        int ans = 0;
        for (int i = m * 2; i < m + n; i++) {
            ans += pi[i] == m;
        }
        return ans;
    }
};