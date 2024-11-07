class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> tmp[2];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            tmp[i & 1].push_back(nums[i]);
        }
        sort(tmp[0].begin(), tmp[0].end());
        sort(tmp[1].begin(), tmp[1].end(), greater<>());
        int ptr = 0;
        for (int i = 0; i < n; i += 2) nums[i] = tmp[0][ptr++];
        ptr = 0;
        for (int i = 1; i < n; i += 2) nums[i] = tmp[1][ptr++];
        return nums;
    }
};