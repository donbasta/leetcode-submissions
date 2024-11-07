class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> L(n), R(n);
        L[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) L[i] = L[i - 1];
            else L[i] = i;
        }
        R[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) R[i] = R[i + 1];
            else R[i] = i;
        }
        vector<int> ret;
        for (int i = k; i < n - k; i++) {
            if (L[i  - 1] <= i - k && R[i + 1] >= i + k) ret.push_back(i);
        }
        return ret;
    }
};