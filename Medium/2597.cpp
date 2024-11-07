class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        vector<int> ada(1001);

        function<void(int)> bt = [&](int idx) {
            if (idx == n) {
                ret++;
                return;
            }
            if (nums[idx] >= k && ada[nums[idx] - k]) {
                bt(idx + 1);
            } else {
                ada[nums[idx]]++;
                bt(idx + 1);
                ada[nums[idx]]--;
                bt(idx + 1);
            }
        };

        bt(0);

        return ret - 1;
    }
};