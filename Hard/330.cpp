class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long itv = 0;
        int k = nums.size();
        int add = 0;
        for (int i = 0; i < k; i++) {
            while (itv < 1ll * nums[i] - 1) {
                itv = (itv * 2 + 1);
                add++;
                if (itv >= n) {
                    return add;
                }
            }
            itv = itv + nums[i];
            if (itv >= n) {
                return add;
            }
        }
        while (itv < n) {
            itv = (itv * 2 + 1);
            add++;
        }
        return add;
    }
};