class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> ki(n, -1), ka(n, n);
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && tmp.back().second <= nums[i]) {
                ka[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, nums[i]);
        }
        tmp.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && tmp.back().second < nums[i]) {
                ki[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < left || nums[i] > right) continue;
            int L = i - ki[i];
            int R = ka[i] - i;
            ans += (L * R);
        }
        return ans;
    }
};