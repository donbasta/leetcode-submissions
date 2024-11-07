class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 0;
        int ans = 0;
        vector<int> toggle(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            int beda = (nums[i] == 0);
            if (beda ^ (cur & 1)) {
                toggle[i] = 1;
            }
            cur += toggle[i];
            if (i >= k - 1) cur -= toggle[i - k + 1];
        }
        for (int i = n - k + 1; i < n; i++) {
            if ((cur & 1) ^ (nums[i] == 0)) {
                return -1;
            }
            if (i >= k - 1) cur -= toggle[i - k + 1];
        }
        ans = accumulate(toggle.begin(), toggle.end(), 0);
        return ans;
    }
};