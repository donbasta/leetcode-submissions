class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        int n = nums.size();
        int rdm_idx = rand() % n;
        int pivot = nums[rdm_idx];
        vector<int> le, mid, ri;
        for (auto e : nums) {
            if (e > pivot) le.push_back(e);
            else if (e == pivot) mid.push_back(e);
            else ri.push_back(e);
        }
        int L = le.size(), M = mid.size();
        if (k <= L) return findKthLargest(le, k);
        else if (k > L + M) return findKthLargest(ri, k - L - M);
        return pivot;
    }
};