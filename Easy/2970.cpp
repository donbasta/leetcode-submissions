class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> tmp;
                for (int k = 0; k < n; k++) {
                    if (k >= i && k <= j) continue;
                    tmp.emplace_back(nums[k]);
                }
                if (tmp.size() <= 1) {
                    ans++;
                } else {
                    bool ok = true;
                    for (int i = 1; i < tmp.size(); i++) {
                        ok &= (tmp[i] > tmp[i - 1]);
                    }
                    ans += ok;
                }
            }
        }
        return ans;
    }
};