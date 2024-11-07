class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [&](string a, string b) -> bool {
            if (a.length() == b.length()) {
                return a < b;
            }
            return a.length() < b.length();
        });
        int n = nums.size();
        return nums[n - k];
    }
};