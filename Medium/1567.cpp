class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        for (auto& e : nums) {
            if (e > 0) e = 1;
            else if (e < 0) e = -1;
        }
        int l = 0;
        int ans = 0;
        while (l < n) {
            if (nums[l] == 0) {l++; continue;}
            int r = l;
            int cnt_neg = 0;
            int last_neg = -1;
            while (r < n && nums[r] != 0) {
                if (nums[r] == -1) {
                    cnt_neg++;
                    last_neg = r;
                }
                r++;
            }
            while (l < r) {
                if (cnt_neg & 1) {
                    ans = max(ans, last_neg - l);
                } else {
                    ans = max(ans, r - l);
                }
                if (nums[l] == -1) cnt_neg--;
                l++;
            }
        }
        return ans;
    }
};