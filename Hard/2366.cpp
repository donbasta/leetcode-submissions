class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums.back();
        long long ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            //nums[i] jadi t, t, ..., t where t <= last or t, t, t...., t, t+1, .., t+1 where t+1 <= last
            int l = 0, r = nums[i] - 1;
            int ok;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int a = nums[i] / (mid + 1);
                int b = a + (nums[i] % (mid + 1) != 0);
                if (b <= last) {
                    ok = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans += ok;
            last = nums[i] / (ok + 1);
        }
        return ans;
    }
};