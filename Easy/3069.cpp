class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1, a2;
        a1.push_back(nums[0]), a2.push_back(nums[1]);
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (a1.back() > a2.back()) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }   
        for (auto e : a2) a1.push_back(e);
        return a1;
    }
};