class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> ada;
        for (auto e : nums) ada[e] = true;
        int n = nums[0].length();
        for (int i = 0; i < n; i++) {
            int cur_dig = nums[0][i] - '0';
            nums[0][i] = (char) (1 - cur_dig + '0');
            if (ada.find(nums[0]) == ada.end()) return nums[0];
            nums[0][i] = (char) (cur_dig + '0');
        }
        assert(false);
        return "";
    }
};