class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int B = 30;
        int n = nums.size();
        int r = 0;
        int ans = 1;
        vector<int> tmp(B + 1);
        for (int i = 0; i <= B; i++) tmp[i] = ((nums[0] >> i) & 1);
        for (int i = 0; i < n; i++) {
            while ((r < (n - 1)) && (*max_element(tmp.begin(), tmp.end()) <= 1)) {
                r++;
                for (int j = 0; j <= B; j++) tmp[j] += ((nums[r] >> j) & 1);
            }
            if (*max_element(tmp.begin(), tmp.end()) >= 2) ans = max(ans, r - i);
            else ans = max(ans, r - i + 1);
            for (int j = 0; j <= B; j++) tmp[j] -= ((nums[i] >> j) & 1);
        }
        return ans;
    }
};