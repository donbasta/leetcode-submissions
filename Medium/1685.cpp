class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int pref = 0;
        for (int i = 0; i < n; i++) {
            int lmao = sum - 2 * pref + (2 * i - n) * nums[i];
            res[i] = lmao;
            pref += nums[i];
        }
        return res;
    }
};