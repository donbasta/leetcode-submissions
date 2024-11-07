class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int, int> cnt;
        long long ret = 0;
        int ptr = -1;
        long long cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += cnt[nums[i]];
            cnt[nums[i]]++;
            while (cur >= k) {
                if (ptr >= 0) {
                    if (cur - (cnt[nums[ptr]] - 1) >= k) {
                        cur -= (cnt[nums[ptr]] - 1);
                        cnt[nums[ptr]]--;
                        ptr++;
                    } else {
                        break;
                    }
                } else {
                    ptr++;
                }
            }
            ret += (ptr + 1);
        }
        return ret;
    }
};